void formHttpHeaders(struct httpHeaders &specs, std::string &httpHeaders)
{
    using namespace std;
    
    if(specs.statusCode == 200)
        httpHeaders.append("HTTP/1.1 200 OK\r\n");
    else if(specs.statusCode == 204)
        httpHeaders.append("HTTP/1.1 204 No Content\r\n");
    else
        httpHeaders.append("HTTP/1.1 501 Not Implemented\r\n");
    
    if(specs.contentType == text_html)
        httpHeaders.append("Content-Type: text/html\r\n");
    else if(specs.contentType == text_plain)
        httpHeaders.append("Content-Type: text/plain\r\n");
    else if(specs.contentType == image_gif)
        httpHeaders.append("Content-Type: image/gif\r\n");
    
    if(specs.contentLength > 0)
    {
        httpHeaders.append("Content-Length: ");
        httpHeaders.append(std::to_string(specs.contentLength));
        httpHeaders.append("\r\n");
    }
    
    httpHeaders.append("\r\n");
}