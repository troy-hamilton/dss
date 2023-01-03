int makeTcpListenerSocket(unsigned short portNumber)
{
    int
        serverSocket;
    struct sockaddr_in
        serverSocketAddress;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket == -1)
    {
        printError("socket", __FILE__, __LINE__);
        return -1;
    }
    
    memset(&serverSocketAddress, 0, sizeof(struct sockaddr_in));
    
    serverSocketAddress.sin_family = AF_INET;
    serverSocketAddress.sin_port = htons(portNumber);
    serverSocketAddress.sin_addr.s_addr = INADDR_ANY;
    
    //assigns the address to the socket
    if(bind(serverSocket, (const struct sockaddr*) &serverSocketAddress, 
        sizeof(struct sockaddr_in)) == -1)
    {
        close(serverSocket);
        printError("bind", __FILE__, __LINE__);
        return -1;
    }
    
    //sets the socket to listen mode.
    if(listen(serverSocket, 4096) == -1)
    {
        close(serverSocket);
        printError("listen", __FILE__, __LINE__);
        return -1;
    }
    
    return serverSocket;
}

int checkForPendingBytes(int fd)
{
    int bytesPending;
    ioctl(fd, FIONREAD, &bytesPending);
    return bytesPending;
}
