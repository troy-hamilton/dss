template<typename T, typename N>
void putne(const T *start, const N length)
{
    for(N i = 0; i < length; i++)
    {
        std::cout << start[i];
    }
    std::cout << std::endl;
}