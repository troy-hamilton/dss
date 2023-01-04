struct httpmap
{
    int method;
    struct metabuf url;    
};

enum // http methods
{
    get,
    post,
    unknown
};

struct httpHeaders // http replies
{
    int statusCode;
    int contentType;
    int contentLength;
};

enum // status codes
{
    sc_200_ok = 200
    
};

enum // content types
{
    text_plain = 1,
    text_html,
    image_gif
};
