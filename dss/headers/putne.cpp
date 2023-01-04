template<typename T, typename N>
void putne(const T *start, const N length)
{
    for(N i = 0; i < length; i++)
    {
        std::cout << start[i];
    }
    std::cout << std::endl;
}

void putne(metabuf &infoBuf)
{
    if(infoBuf.length == 0)
    {
        std::cout << "0 Length Sequence Detected" << std::endl;
        return;
    }
    
    char *p = (char*)infoBuf.start;
    for(long i = 0; i < infoBuf.length; i++)
    {
        std::cout << *p;
        p++;
    }
    std::cout << std::endl;
}
