void cleanup(struct metabuf &infoBuf)
{
    free(infoBuf.start);
    infoBuf.length = 0;
}

void cleanup(int fd)
{
    close(fd);
}
