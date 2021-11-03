#include "Terminal.h"

using namespace std;

namespace uqac::networkLib
{

	std::shared_ptr<Connection> Terminal::Accept(SOCKET ListenSocket)
	{
		// create socket
		SOCKET ClientSocket;
		ClientSocket = INVALID_SOCKET;

		ClientSocket = accept(ListenSocket, NULL, NULL);
		if (ClientSocket == INVALID_SOCKET) {
			cout << "Couldnt accept : ", WSAGetLastError();
			closesocket(ListenSocket);
			return nullptr;
		}
		return make_shared<ConnectionTCP>(ClientSocket);
	}


}