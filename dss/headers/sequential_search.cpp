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

/*
template <typename T, typename N>
bool findNestedTerm(const T bucket[], const T start[], const T delim[], const N bucketlen,
    const N startlen, const N delimlen, struct metabuf &infoBuf)
{
    N frontIndex = findTermIndex(bucket, start, bucketlen, startlen);
    if(frontIndex == -1)
        return false;
    
    frontIndex += startlen;
    
    N backIndex = findTermIndex(&bucket[frontIndex], delim, bucketlen - frontIndex, 
        delimlen);
    if(backIndex == -1)
        return false;
    
    backIndex += frontIndex;

    infoBuf.start = (unsigned char*)&bucket[frontIndex];
    infoBuf.length = backIndex - frontIndex;

    return true;
}
*/

bool findNestedTerm(struct metabuf &raw, const char* front, const char* back, struct metabuf &mid)
{
    char *bucket;
    int bucketlen;
    
    char *foundMid;
    int midlen;
    
    bucket = (char*)raw.start;
    bucketlen = (int)raw.length;
    
    //find front index
    int frontIndex = findTermIndex(bucket, front, bucketlen, (int)strlen(front));
    if(frontIndex == -1)
        return false;
    
    frontIndex += (int)strlen(front);
    
    
    int backIndex = findTermIndex(&bucket[frontIndex], back, bucketlen - frontIndex, (int)strlen(back));
    if(backIndex == -1)
        return false;
    
    backIndex += frontIndex;

    midlen = backIndex - frontIndex;
    
    foundMid = &bucket[frontIndex];
    
    mid.start = (unsigned char*)foundMid;
    mid.length = (int)midlen;

    return true;
}