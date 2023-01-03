template <typename T, typename N>
const N findTermIndex(const T bucket[], const T term[], const N bucketlen, const N termlen)
{
    for(N i = 0; i <= bucketlen - termlen; i++)
    {
        if(bucket[i] == term[0])
        {
            for(N j = 0; j < termlen; j++)
            {
                if(term[j] == bucket[i + j])
                {
                    if(j == termlen - 1)
                    {
                        return i;
                    }
                }
                else
                    break;
            }
        }
    }
    
    return -1;
}

template <typename T, typename N>
const T* findTermAddress(const T bucket[], const T term[], const N bucketlen, const N termlen)
{
    N termIndex = findTermIndex(bucket, term, bucketlen, termlen);
    
    if(termIndex == -1)
        return nullptr;
    
    const T* address = &bucket[termIndex];
    
    return address;
}
