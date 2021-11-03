#pragma once
#include <WinSock2.h>
#include "Connection.h"

namespace uqac::networkLib
{
	class ConnectionTCP : public Connection
	{
	public:
		ConnectionTCP();
		ConnectionTCP(SOCKET socket); // faudrait filer un pointeur
		~ConnectionTCP();

	public:
		int Send(std::string message) override;
		int Receive() override;

	};
}

