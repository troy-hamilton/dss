#include <unistd.h>         // read() getpagesize()
#include <cstdlib>         // malloc() realloc() free()
#include <netinet/in.h> //sockaddr_in
#include <sys/socket.h> //socket bind listen accept
#include <cstring>
#include <cstdio>

#include "metabuf.hpp"
#include "dynaread.hpp"
#include "dynaread.cpp"
#include "sequential_search.hpp"
#include "sequential_search.cpp"
#include "print_error.hpp"
#include "print_error.cpp"
#include "tcp_sockets.hpp"
#include "tcp_sockets.cpp"
#include "cleanup.hpp"
#include "cleanup.cpp"

#include "step.cpp"