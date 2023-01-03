int dynaread(int fd, const long max, struct metabuf *infobuf);
/*
    dynaread() will read at most max bytes from fd, and will write
    information about the dynamically allocated buffer where the message is located
    into infobuf;
    
    returns 0 on success, returns -1 on error.
    On error, dynaread is guaranteed to fail gracefully and not result in memory
    leaks.
*/
