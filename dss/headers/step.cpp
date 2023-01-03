void step(int client)
{
    struct metabuf raw;
    
    int retval = dynaread(client, 8192, &raw);
    if(retval == -1)
    {
        printError("dynaread", __FILE__, __LINE__);
        cleanup(raw);
        cleanup(client);
        return;
    }
    
    printf("%s\n", (char*)raw.start);
    
    const char*
        reply = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello";
        
    retval = write(client, reply, strlen(reply));
    
    cleanup(raw);
    cleanup(client);
}
