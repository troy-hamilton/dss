void step(int client)
{
	struct metabuf raw;
	
	int retval = dynaread(client, 8192, &raw);
	if(retval == -1)
	{
		cleanup(raw);
		cleanup(client);
		return;
	}
	
	printf("%s\n", (char*)raw.start);
	
	
}
