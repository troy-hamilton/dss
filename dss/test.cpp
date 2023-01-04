#include "headers/all.hpp"

// currently testing formHttpHeaders(struct httpHeaders &specs, struct metabuf &headerBuf)

int main()
{
    struct httpHeaders specs;
    specs.statusCode = 200;
    specs.contentType = text_html;
    specs.contentLength = 999;
    
    struct metabuf headers;
    
    formHttpHeaders(specs, headers);
    
    putne(headers);
    
}
