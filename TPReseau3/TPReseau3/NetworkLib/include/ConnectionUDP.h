#pragma once

#include "Connection.h"
#include <stdio.h>
#include <WinSock2.h>

namespace uqac::networkLib
{
	class ConnectionUDP : public Connection
	{
	private:
		int slen;

	public:
		sockaddr_in info;

		ConnectionUDP();
		ConnectionUDP(SOCKET s, sockaddr_in info);
		~ConnectionUDP();

	public:
		int Send(std::string message) override;
		int Receive() override;

	};
}

