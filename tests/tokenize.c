#include "monty.h"

/**
 * tokenize - tokenizes a string into an array of strings
 * @line: line to be tokenized
 * Return: purse
 */

char **tokenize(char *line)
{
	int i;
	int bufsize = 800;

	char *delim = " \n\t";
	char *token;

	token = strtok(line, delim);

	purse = malloc(sizeof(char) * bufsize);
	if (!purse)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; token != NULL; i++)
	{
		purse[i] = token;
		token = strtok(NULL, delim);
	}
	purse[i] = NULL;
	return (purse);
}
