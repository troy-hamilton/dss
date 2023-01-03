int makeTcpListenerSocket(unsigned short portNumber);
/*
    makeTcpListenerSocket() tells the operating system to make
    a tcp socket file descriptor in a listening state, which is suitable
    for the accept() system call to use.
*/

int checkForPendingBytes(int fd);
/*
    checkForPendingBytes() will check a socket to see
    if there are any bytes pending, which can be read().
    
    returns 0 if there are no bytes available.
    returns the number of bytes available otherwise.
*/