bool fileDiskToMemory(const char *filePath, struct metabuf &buf)
{
    // get length of file
    // malloc a buffer of file length
    // write buffer pointer to buf
    // write buffer length to buf
    
    struct stat finfo;
    
    if(stat(filePath, &finfo) == -1)
    {
        printError("stat", __FILE__, __LINE__);
        std::cout << "searched for file: " << filePath << std::endl;
        return false;
    }
    
    void * spot = malloc(finfo.st_size);
    if(spot == NULL)
    {
        printError("malloc", __FILE__, __LINE__);
        return false;
    }
    
    FILE *fp = fopen(filePath, "r");
    if(fp == NULL)
    {
        free(spot);
        printError("fopen", __FILE__, __LINE__);
        return false;
    }
    
    if(fread(spot, finfo.st_size, 1, fp) != 1)
    if(fp == NULL)
    {
        fclose(fp);
        free(spot);
        printError("fread", __FILE__, __LINE__);
        return false;
    }
    
    buf.start = spot;
    buf.length = finfo.st_size;
    
    fclose(fp);
    return true;
}
