#include "ConnectionTCP.h"
#include <vector>

namespace uqac::networkLib
{

	ConnectionTCP::ConnectionTCP()
	{
		// create socket
	}

	ConnectionTCP::ConnectionTCP(SOCKET socket)
	{
		s = socket;
	}

	ConnectionTCP::~ConnectionTCP()
	{
		closesocket(s);
	}


	int ConnectionTCP::Send(std::string message)
	{
		int iResult = send(s, message.c_str(), message.size(), 0);
		if (iResult == SOCKET_ERROR) {
			std::cerr << "send failed : ", WSAGetLastError();
			closesocket(s);
			return -1;
		}
		return 1;
	}


	int ConnectionTCP::Receive()
	{
		int iResult;
		do {
			iResult = recv(s, buf, (int)strlen(buf), 0);
			if (iResult > 0)
			{
				// Simplifiable
				std::string message(buf, iResult);
				msg = message;
				return 1;
			}
			return -1;
		} while (iResult > 0);
	}

}
