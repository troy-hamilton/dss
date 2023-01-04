#include <unistd.h>         // read() getpagesize()
#include <cstdlib>         // malloc() realloc() free()
#include <netinet/in.h> //sockaddr_in
#include <sys/socket.h> //socket bind listen accept
#include <cstring>
#include <cstdio>
#include <sys/ioctl.h>
#include <iostream>
#include <sys/stat.h>

#include "metabuf.hpp"
#include "http_structs_and_enums.hpp"
#include "putne.hpp"
#include "putne.cpp"
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
#include "http_parsing.hpp"
#include "http_parsing.cpp"
#include "disk_to_memory.hpp"
#include "disk_to_memory.cpp"
#include "formHttpHeaders.cpp"
#include "../cliq/cliqs.hpp"
#include "flowpath.cpp"
#include "step.cpp"
