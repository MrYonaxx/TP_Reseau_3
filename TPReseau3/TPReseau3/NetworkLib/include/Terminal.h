#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include "ConnectionTCP.h"

namespace uqac::networkLib
{
	class Terminal 
	{

		public:
			std::shared_ptr<Connection> Accept(SOCKET s);
	};
}