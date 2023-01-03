int dynaread(int fd, const long max, struct metabuf *infobuf)
{
    unsigned char
        *buffer, *temp_pointer;
    ssize_t 
        bytes_read = 0, total_bytes = 0, PAGE_SIZE, page_increments, 
		size_after_realloc;
    
    (*infobuf).length = 0; // initial setup
    (*infobuf).start = NULL; // initial setup
    
    PAGE_SIZE = (size_t)getpagesize();
    if(max < PAGE_SIZE)
    {
        PAGE_SIZE = max;
    }
    
    buffer = (unsigned char*)malloc(PAGE_SIZE); // malloc an initial buffer
    if(buffer == NULL)
        return -1;
    
    page_increments = 1;
    size_after_realloc = PAGE_SIZE;
    
    while(total_bytes < max)
    {                                               //assures no overflow
        bytes_read = read(fd, buffer + total_bytes, size_after_realloc - total_bytes);
        if(bytes_read < 0)
        {
            free(buffer);
            return -1;
        }
        
        if(bytes_read == 0) // breaks if reading is finished
        {
            break;
        }
        
        total_bytes += bytes_read;
        if(total_bytes > max - 1) // stops if the max limit is reached
        {
            break;
        }
        
        // checks if the buffer got full, reallocs then continues if necessary
        if(bytes_read == PAGE_SIZE)
        {
            page_increments++;
            size_after_realloc = page_increments * PAGE_SIZE;
            if(size_after_realloc > max)
            {
                size_after_realloc = max;
            }
            
            temp_pointer = (unsigned char*)realloc(buffer, size_after_realloc);
            if(temp_pointer == NULL)
            {
                free(buffer);
                return -1;
            }
            
            buffer = temp_pointer;
        }
        else
            break;
    }
    
    //resize buffer to a smaller size.
    temp_pointer = (unsigned char*)realloc(buffer, total_bytes);
    if(temp_pointer == NULL)
    {
        free(buffer);
        return -1;
    }
    
    buffer = temp_pointer;
    
    (*infobuf).length = (long)total_bytes; // note to self "(*type).member" is the same as "type -> member"
    (*infobuf).start = (void*)buffer;
    
    return 0;
}
