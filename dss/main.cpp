#include "headers/all.hpp"

int main()
{
	int serverSocket = makeTcpListenerSocket(1024);
	if(serverSocket == -1)
    {
        printError("serverSocket", __FILE__, __LINE__);
        return -1;
    }
	
	while(1)
	{
		int clientSocket = accept(serverSocket, NULL, NULL);
		if(clientSocket == -1)
        {
            printError("accept", __FILE__, __LINE__);
            continue;
        }
		
		step(clientSocket);
	}
}