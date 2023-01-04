void sendFavicon(int client)
{    
    struct metabuf faviconImage;
    if(fileDiskToMemory("public/favicon.gif", faviconImage) == false)
        return;
    
    struct httpHeaders specs;
    
    specs.statusCode = sc_200_ok;
    specs.contentType = image_gif;
    specs.contentLength = faviconImage.length;
    
    std::string headers;
    formHttpHeaders(specs, headers);
    
    write(client, headers.c_str(), headers.length());
    write(client, faviconImage.start, faviconImage.length);
    cleanup(faviconImage);
}
