#pragma once
#include <WinSock2.h>
#include <iostream>

namespace uqac::networkLib
{
	class Connection
	{

	protected:
		char buf[512];

	public:
		SOCKET s;
		std::string msg;

		virtual int Send(std::string message);
		virtual int Receive();

	};
}
