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

	char *delim = " \n\a\t";
	char *token;
	char **wallet;

	token = strtok(line, delim);

	wallet = malloc(sizeof(char) * bufsize);
	if (!wallet)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; token != NULL; i++)
	{
		wallet[i] = token;
		token = strtok(NULL, delim);
	}
	if ((!token && !*wallet) || *wallet[0] == '#')
	{
		free(wallet);
		free(token);
		return (NULL);
	}
	wallet[i] = NULL;
	return (wallet);
}
