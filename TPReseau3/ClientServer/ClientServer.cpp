#pragma once

#include <iostream>
#include "NetworkLib.h"
#include "ClassRegistry.h"
#include <string>
#include <vector>
#include "windows.h"
#include "Enemy.h"
#include "Player.h"

using namespace std;
using namespace uqac::networkLib;
using namespace uqac::replication;
using namespace uqac::networkGame;


// =======================================  S E R V E R  =======================================

vector<shared_ptr<Connection>> listConnection;

// Callback
void CreatePlayer(shared_ptr<Connection> newConnection)
{
	listConnection.push_back(newConnection);

	// Create Player


	// Create Enemy
	if (listConnection.size() >= 2) 
	{
		GameObject* enemy = ClassRegistry::GetInstance()->Create(ClassID::EnemyID);
		// Add enemy to LinkingContext
	}
}

void RemovePlayer(shared_ptr<Connection> newConnection) 
{
	//listConnection.erase(newConnection);
}

void SendDataToAll() 
{
	std::string dataSerialized;
	for (int i = 0; i < listConnection.size(); ++i)
	{
		listConnection[i]->Send(dataSerialized);
	}
}


void Server(NetworkLib& net, int protocol, std::string ip, int port)
{
	//Server
	string username;
	string message;

	ConfigCallback callbacks;

	callbacks.OnConnection = CreatePlayer;
	callbacks.OnDisconnection = RemovePlayer;
	//callbacks.OnMsgReceived = SendMessageAll;

	if (net.Listen(ip, port, protocol, callbacks) < 0)
		std::cout << "Oups";

	while (true)
	{
		// Si on appuis sur une touche on modifie tout
		// On appel ReplicationManager Update
		// On envois un msg à toutes les connection avec le contenu de Update
		
		Sleep(1);
	}

}




// =======================================  C L I E N T  =======================================
void Deserialize(std::shared_ptr<Connection> connection) 
{
	std::string msg = connection->msg;
}

void ConnectionLost(std::shared_ptr<Connection> connection)
{
	// Abort all
}

void Client(NetworkLib& net, int protocol, std::string ip, int port)
{
	string username;
	string message;

	cout << "Username ?\n";
	std::getline(std::cin, username);
	//cin >> username;

	// Callbacks
	ConfigCallback callbacks;
	callbacks.OnMsgReceived = Deserialize;
	callbacks.OnDisconnection = ConnectionLost;

	//Connection au serveur
	std::shared_ptr<Connection> connection = net.Connect(ip, port, protocol, callbacks);
	if (connection == nullptr)
	{
		cout << "Argh\n";
		return;
	}

	//Chat
	/*cout << "/exit pour quitter\n";
	while (true) {
		std::getline(std::cin, message);
		//cin >> message;
		if (message == "/exit")
			break;
		message = "[" + username + "]:" + message;
		connection->Send(message.c_str());
		std::cout << message;
		std::cout << '\n';
	}*/
}



// ================================================  M A I N  ================================================
std::function<GameObject* ()> createEnemy;
std::function<GameObject* ()> createPlayer;

Enemy* CreateGameObjectEnemy()
{
	std::cout << "Pouet pouet";
	return new Enemy();
}

Player* CreateGameObjectPlayer()
{
	return new Player();
}

void RegisterClasses() 
{
	createEnemy = std::bind(CreateGameObjectEnemy);
	Enemy enemy; // C'est cheum mais bon
	ClassRegistry::GetInstance()->RegisterClassA(enemy, createEnemy);

	/*createPlayer = std::bind(CreateGameObjectPlayer);
	Player player;
	ClassRegistry::GetInstance()->RegisterClassA(player, createPlayer);*/
}

int main(int argc, char** argv) //usage: -ip [IP] -port [PORT] -protocole [0=TCP;1=UDP]
{
	string answer;

	// Client ou Server
	cout << "Client(0) ou Server(1) ?";
	std::getline(std::cin, answer);

	// Initialization Reseau
	// Default parameter
	int protocol = 0;
	int port = 8888;
	string ip = "127.0.0.1";

	//Validate parameters
	if (argc == 7)
	{
		char* p;
		long arg = strtol(argv[6], &p, 10);
		protocol = (int)arg;

		arg = strtol(argv[4], &p, 10);
		port = arg;

		ip = std::string(argv[2]);
		std::cout << ip << "\n" << port << "\n" << protocol << "\n";
	}
	else if (argc > 1)
	{
		cout << "usage: -ip [IP] -port [PORT] -protocole [0=TCP;1=UDP]\n";
		return -1;
	}
	cout << "Hello CMake." << endl;

	// Init Network Lib
	NetworkLib net;
	int err = net.Initialize();
	if (err == -1) {
		cerr << "Failed to initialized";
		return -1;
	}

	// Enregistre les fonction pour créer les classes dans le Replication Manager
	RegisterClasses();

	ClassRegistry::GetInstance()->Create(ClassID::PlayerID);
	return 0;

	if (answer == "0") {
		// Client
		Client(net, protocol, ip, port);
	}
	else if (answer == "1") {
		// Server
		Server(net, protocol, ip, port);
	}

	net.Close();
	return 0;
}