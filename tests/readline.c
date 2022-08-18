#include "monty.h"



char **get_tok(int fd)
{
	int i, flag;
	char *lineptr = NULL;
	size_t n = 0;
	

	for (i = 0; flag != EOF; i++)
	{
		flag = getline(&lineptr, &n, fd);
		if (flag > 0)
		{
			purse = tokenize(lineptr);
		
