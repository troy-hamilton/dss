/*
    spec out the http header
    load the page into a buffer
    send the headers to the client
    send the page to the client
    free the buffer
*/

void sendIndexPage(int client)
{    
    struct metabuf indexPage;
    if(fileDiskToMemory("public/index.html", indexPage) == false)
        return;
    
    struct httpHeaders specs;
    
    specs.statusCode = sc_200_ok;
    specs.contentType = text_html;
    specs.contentLength = indexPage.length;
    
    std::string headers;
    formHttpHeaders(specs, headers);
    
    write(client, headers.c_str(), headers.length());
    write(client, indexPage.start, indexPage.length);
    cleanup(indexPage);
}
