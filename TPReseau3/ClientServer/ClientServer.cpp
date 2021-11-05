#pragma once

#include <iostream>
#include "NetworkLib.h"
#include "ClassRegistry.h"
#include <string>
#include <vector>
#include "windows.h"
#include "Enemy.h"
#include "Player.h"
#include "ReplicationManager.h"

// Ne plus faire ça c'est le prof qui l'a dit
/*
using namespace std;
using namespace uqac::networkLib;
using namespace uqac::replication;
using namespace uqac::networkGame;
*/

int protocol = 0;
uqac::replication::ReplicationManager replicationManager;
//uqac::networkLib::NetworkLib networkLib;



// =======================================  S E R V E R  =======================================

std::vector<std::shared_ptr<uqac::networkLib::Connection>> listConnection;

void ReplicateObject()
{
	std::vector<char> dataSerialized = replicationManager.Update(protocol);
	std::string msg = std::string(dataSerialized.begin(), dataSerialized.end());

	for (int i = 0; i < listConnection.size(); ++i)
	{
		listConnection[i]->Send(msg);
	}
}

// Callback
void CreatePlayer(std::shared_ptr<uqac::networkLib::Connection> newConnection)
{
	listConnection.push_back(newConnection);

	// Create Player
	GameObject* player = ClassRegistry::GetInstance()->Create(ClassID::PlayerID);
	replicationManager.AddObject(player);
	std::cout << "Player created \n";

	// Create Enemy
	if (listConnection.size() >= 2) 
	{
		GameObject* enemy = ClassRegistry::GetInstance()->Create(ClassID::EnemyID);
		replicationManager.AddObject(enemy);
		std::cout << "Enemy created \n";
	}


	ReplicateObject();
	std::cout << listConnection.size() << '\n';
	std::cout << "On envoi tout \n";
}

void RemovePlayer(std::shared_ptr<uqac::networkLib::Connection> newConnection)
{
	listConnection.erase(std::find(listConnection.begin(), listConnection.end(), newConnection));
	// Remove player 
}


void Server(uqac::networkLib::NetworkLib& net, std::string ip, int port)
{
	//Server
	std::string message;

	uqac::networkLib::ConfigCallback callbacks;

	callbacks.OnConnection = CreatePlayer;
	callbacks.OnDisconnection = RemovePlayer;

	if (net.Listen(ip, port, protocol, callbacks) < 0)
		std::cout << "Oups";

	while (true)
	{
		std::getline(std::cin, message);
		ReplicateObject();
		std::cout << "On envoi tout \n";

		Sleep(1);
	}

}








// =======================================  C L I E N T  =======================================
void DataReceived(std::shared_ptr<uqac::networkLib::Connection> data)
{
	std::cout << "J'ai reçu un truc ! \n";
	std::string msg = data->msg;
	replicationManager.Read(msg);
}

void ConnectionLost(std::shared_ptr<uqac::networkLib::Connection> connection)
{
	std::cout << "Conection perdue";
	// Abort all
}

void Client(uqac::networkLib::NetworkLib& net, std::string ip, int port)
{
	std::string username;
	std::string message;

	std::cout << "Username ?\n";
	std::getline(std::cin, username);

	// Callbacks
	uqac::networkLib::ConfigCallback callbacks;
	callbacks.OnMsgReceived = DataReceived;
	callbacks.OnDisconnection = ConnectionLost;

	//Connection au serveur
	std::shared_ptr<uqac::networkLib::Connection> connection = net.Connect(ip, port, protocol, callbacks);
	if (connection == nullptr)
	{
		std::cout << "Argh\n";
		return;
	}

	std::cout << "Connection réussi\n";
	while (true)
	{
		//std::getline(std::cin, message);
		Sleep(1);
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
std::function<uqac::replication::GameObject* ()> createEnemy;
std::function<uqac::replication::GameObject* ()> createPlayer;

uqac::networkGame::Enemy* CreateGameObjectEnemy()
{
	return new uqac::networkGame::Enemy();
}

uqac::networkGame::Player* CreateGameObjectPlayer()
{
	return new uqac::networkGame::Player();
}

void RegisterClasses() 
{
	createEnemy = std::bind(CreateGameObjectEnemy);
	uqac::networkGame::Enemy enemy; // C'est cheum mais bon
	ClassRegistry::GetInstance()->RegisterClassA(enemy, createEnemy);


	createPlayer = std::bind(CreateGameObjectPlayer);
	uqac::networkGame::Player player;
	ClassRegistry::GetInstance()->RegisterClassA(player, createPlayer);
}

int main(int argc, char** argv) //usage: -ip [IP] -port [PORT] -protocole [0=TCP;1=UDP]
{
	std::string answer;

	// Client ou Server
	std::cout << "Client(0) ou Server(1) ?";
	std::getline(std::cin, answer);

	// Initialization Reseau
	// Default parameter
	protocol = 0;
	int port = 8888;
	std::string ip = "127.0.0.1";

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
		std::cout << "usage: -ip [IP] -port [PORT] -protocole [0=TCP;1=UDP]\n";
		return -1;
	}
	std::cout << "Hello CMake." << std::endl;

	// Init Network Lib
	uqac::networkLib::NetworkLib net;
	int err = net.Initialize();
	if (err == -1) {
		std::cerr << "Failed to initialized";
		return -1;
	}

	// Enregistre les fonction pour créer les classes dans le Replication Manager
	replicationManager = ReplicationManager();
	RegisterClasses();

	if (answer == "0") {
		// Client
		Client(net, ip, port);
	}
	else if (answer == "1") {
		// Server
		Server(net, ip, port);
	}

	net.Close();
	return 0;
}