// NetworkLib.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets.

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

// TODO: Référencez ici les en-têtes supplémentaires nécessaires à votre programme.

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <thread>
#include <vector>
#include <functional>
#include "Terminal.h"
#include "ConnectionTCP.h"
#include "ConnectionUDP.h"

namespace uqac::networkLib
{
	struct ConfigCallback
	{
		std::function<void(std::shared_ptr<Connection>)> OnMsgReceived;
		std::function<void(std::shared_ptr<Connection>)> OnConnection;
		std::function<void(std::shared_ptr<Connection>)> OnDisconnection;
	};

	class NetworkLib
	{

	private:
		Terminal terminal;
		std::thread threadNetwork;
		bool threadRunning;




	public:

		int Initialize();
		void Close();

		std::shared_ptr<Connection> Connect(std::string adressIP, int port, int protocol, ConfigCallback callbacks);
		int Listen(std::string adressIP, int port, int protocol, ConfigCallback callbacks);


		// Pour les thread 
		void UpdateListen(SOCKET listeningSocket, std::shared_ptr<Connection> defaultReceive, ConfigCallback callbacks);
		void UpdateListenUDP(std::shared_ptr<ConnectionUDP> defaultReceive, ConfigCallback callbacks);
	};


}