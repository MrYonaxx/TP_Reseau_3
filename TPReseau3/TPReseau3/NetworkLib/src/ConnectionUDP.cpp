#include "ConnectionUDP.h"

namespace uqac::networkLib
{
	ConnectionUDP::ConnectionUDP()
	{

	}

	ConnectionUDP::ConnectionUDP(SOCKET s, sockaddr_in info)
	{
		this->s = s;
		this->info = info;
		slen = sizeof(info);
	}

	ConnectionUDP::~ConnectionUDP()
	{
		closesocket(s);
	}



	int ConnectionUDP::Send(std::string message)
	{
		//send the message
		if (sendto(s, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr*)&info, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//free(buf);

		return 0;
	}

	int ConnectionUDP::Receive()
	{
		int iResult = recvfrom(s, buf, strlen(buf), 0, (struct sockaddr*)&info, &slen);
		if (iResult == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}
		std::string message(buf, iResult);
		msg = message;
		//free(buf);
		return 0;
	}



}