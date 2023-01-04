/*
struct httpHeaders
{
    int statusCode;
    int contentType;
    int contentLength;
};

enum
{
    text_plain = 1,
    text_html
};

void formHttpHeaders(struct httpHeaders &specs, struct metabuf &headerBuf)
{
    // set up the headerBuf
    headerBuf.start = nullptr;
    headerBuf.length = 0;
    
    using namespace std;
    string hed;
    
    if(specs.statusCode == 200)
        hed.append("HTTP/1.1 200 OK\r\n");
    else if(specs.statusCode == 204)
        hed.append("HTTP/1.1 204 No Content\r\n");
    else
    {
        printError("formHttpHeaders", __FILE__, __LINE__);
        return;
    }
    
    if(specs.contentType == text_html)
        hed.append("Content-Type: text/html\r\n");
    else if(specs.contentType == text_plain)
        hed.append("Content-Type: text/plain\r\n");
    
    if(specs.contentLength > 0)
    {
        hed.append("Content-Length: ");
        hed.append(std::to_string(specs.contentLength));
        hed.append("\r\n");
    }
    
    hed.append("\r\n");
    
    void * spot = malloc(hed.size());
    if(spot == NULL)
        return;
    
    strcpy((char*)spot, hed.c_str());
    
    headerBuf.start = spot;
    headerBuf.length = hed.length();
    return;
}

void methodWasGet(int &client, struct httpmap &map)
{
    struct metabuf headers;
    struct httpHeaders specs;
    struct metabuf body;
    
    // see what the url was
    if(map.url.length == 0)
    {
        specs.statusCode = 200;
        specs.contentType = text_html;
        
        if(fileDiskToMemory("public/index.html", body) == false)
        {
            printError("fileDiskToMemory", __FILE__, __LINE__);
            return;
        }
        
        specs.contentLength = body.length; // load body into memory and write length in here
        formHttpHeaders(specs, headers);
        write(client, headers.start, headers.length);
        write(client, body.start, body.length);
        
        free(headers.start);
        free(body.start);
    }
    else
    {
        specs.statusCode = 204;
        specs.contentType = -1;
        specs.contentLength = -1;
        formHttpHeaders(specs, headers);
        write(client, headers.start, headers.length);
    }
    
}
*/
void methodWasGet(int &client, struct httpmap &map)
{
    if(map.url.length == 0)
    {
        sendIndexPage(client);
    }
    else if(memcmp(map.url.start, "index.html", strlen("index.html")) == 0)
    {
        sendIndexPage(client);
    }
    else if(memcmp(map.url.start, "favicon.ico", strlen("favicon.ico")) == 0)
    {
        sendFavicon(client);
    }
    else if(memcmp(map.url.start, "login.html", strlen("login.html")) == 0)
    {
        sendLoginPage(client);
    }
    else if(memcmp(map.url.start, "private/users/", strlen("private/users/")) == 0)
    {
        privateUrl(client, map);
    }
}

void methodWasPost(int &client, struct httpmap &map)
{
    std::cout << "No clue what to do if the method was post." << std::endl;
}

void methodWasUnknown(int &client, struct httpmap &map)
{
    std::cout << "No clue what to do if the method was unknown." << std::endl;
}

void flowpath(int &client, struct httpmap &map)
{
    enum
    {
        get,
        post,
        unknown
    };
    
    // split program flow into different sectional functions
    // these functions will further check for conditions in the map
    if(map.method == get)
        methodWasGet(client, map);
    else if(map.method == post)
        methodWasPost(client, map);
    else
        methodWasUnknown(client, map);
    
    
}
