#include "monty.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if success.
 */

int main(int ac, char **av)
{
	stack_t *head = NULL;
	unsigned int lineno = 1;
	FILE *fp;
	char *lineptr = NULL;
	size_t size = 0;
	char **purse = NULL;

	if (ac != 2)
		_perror(av[0], 0, 0);
	fp = fopen(av[1], "r");
	if (!fp)
		_perror(av[1], 0, 1);
	while (getline(&lineptr, &size, fp) != -1)
	{
		purse = tokenize(lineptr);
		if (!purse)
		{
			lineno++;
			continue;
		}
		matchf(purse, lineptr, &head, fp, lineno);
		lineno++;
		free(purse);
	}
	free(lineptr);
	free_dlist(head);
	fclose(fp);
return (0);
}
