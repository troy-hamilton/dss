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
    
    //printf("%s\n", raw.start);
    cleanup(raw);
    cleanup(client);
}
