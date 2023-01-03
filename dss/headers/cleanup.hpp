void cleanup(struct metabuf &infoBuf);
void cleanup(int fd);
/*
	cleanup() will perform resource cleanup on whatever is 
	passed to it.
	
	cleanup can mean free()ing dynamically allocated memory,
	or releasing file descriptors back to the system.
*/
