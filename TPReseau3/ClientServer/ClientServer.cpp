#pragma once

#include <iostream>
#include "NetworkLib.h"
#include "ClassRegistry.h"
#include <string>
#include <vector>
#include "windows.h"

using namespace std;
using namespace uqac::networkLib;
using namespace uqac::replication;


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
		GameObject* enemy = ClassRegistry::GetInstance()->Create(ClassID::Enemy);
		// Add enemy to LinkingContext
	}
}

void RemovePlayer(shared_ptr<Connection> newConnection) 
{
	//listConnection.erase(newConnection);
}



void Server(NetworkLib& net)
{
	//Server
	string username;
	string message;

	uqac::networkLib::ConfigCallback callbacks;

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

void Client(NetworkLib& net)
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

	// Enregistrer les fonction pour créer les classes dans le Replication Manager
	// ...



	if (answer == "0") {
		// Client
		Client(net);
	}
	else if (answer == "1") {
		// Server
		Server(net);
	}

	net.Close();
	return 0;
}