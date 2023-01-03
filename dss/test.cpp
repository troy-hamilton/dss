#include "headers/all.hpp"

// currently testing parseHttp
// void parseHttp(struct metabuf &raw, struct httpmap &map)
int main()
{
    const char * httpmsg = "POST /troy HTTP/1.1";
    struct metabuf raw;
    raw.start = (unsigned char*)httpmsg;
    raw.length = strlen((char*)raw.start);
    struct httpmap map;
    
    parseHttp(raw, map);
    
    std::cout << "map.method == " << map.method << std::endl;
    std::cout << "map.url == ";
    putne((char*)map.url.start, map.url.length);
    
}