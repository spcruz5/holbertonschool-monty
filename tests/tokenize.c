#include "monty.h"

/**
 * tokenize - tokenizes a string into an array of strings
 * @line: line to be tokenized
 * Return: purse
 */

char **tokenize(char *line)
{
	int i;
	int bufsize = 400;
	char **purse;

	char *delim = " ";
	char *token;

	token = strtok(line, delim);

	purse = malloc(sizeof(char) * bufsize);
	if (!purse)
	{
		perror("Failed to allocate memory");
		exit(1);
	}

	for (i = 0; token != NULL; i++)
	{
		purse[i] = token;
		token = strtok(NULL, delim);
	}
	purse[i] = NULL;
	return (purse);
}



