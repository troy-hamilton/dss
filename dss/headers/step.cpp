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
    
    struct httpmap map;
    
    parseHttp(raw, map);
    
    std::cout << "map.method{" << map.method << '}' << std::endl;
    putne(map.url);
    
    cleanup(raw);
    cleanup(client);
}
