void parseHttp(struct metabuf &raw, struct httpmap &map)
{
    enum
    {
        get,
        post,
        unknown
    };
    
    if(memcmp(raw.start, "GET", 3) == 0)
        map.method = get;
    else if(memcmp(raw.start, "POST", 4) == 0)
        map.method = post;
    else
        map.method = unknown;
    
    findNestedTerm(raw, " /", " H", map.url);
}
