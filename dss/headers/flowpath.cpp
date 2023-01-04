void methodWasGet(int &client, struct httpmap &map)
{
    if(map.url.length == 0)
    {
        sendIndexPage(client);
    }
    else if(memcmp(map.url.start, "index.html", strlen("index.html")) == 0)
    {
        sendIndexPage(client);
    }
    else if(memcmp(map.url.start, "favicon.ico", strlen("favicon.ico")) == 0)
    {
        sendFavicon(client);
    }
    else if(memcmp(map.url.start, "login.html", strlen("login.html")) == 0)
    {
    //    sendLoginPage(client);
    }
    else if(memcmp(map.url.start, "private/users/", strlen("private/users/")) == 0)
    {
    //    privateUrl(client, map);
    }
}

void methodWasPost(int &client, struct httpmap &map)
{
    std::cout << "No clue what to do if the method was post." << std::endl;
}

void methodWasUnknown(int &client, struct httpmap &map)
{
    std::cout << "No clue what to do if the method was unknown." << std::endl;
}

void flowpath(int &client, struct httpmap &map)
{    
    // split program flow into different sectional functions
    // these functions will further check for conditions in the map
    if(map.method == get)
        methodWasGet(client, map);
    else if(map.method == post)
        methodWasPost(client, map);
    else
        methodWasUnknown(client, map);
    
    
}
