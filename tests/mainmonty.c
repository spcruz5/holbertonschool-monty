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
	int i, j, flag, ares, lineno = 0;
	int (*ptr)(stack_t, int);
	FILE *fp;
	char **lineptr = NULL;
	size_t size = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r")
	if (!fp)
		_perror(av[1], NULL, 1);
	for (i = 0; flag != EOF; i++)
	{
		lineptr = NULL;
		size = 0;
		flag = getline(&lineptr, &n, fp);
		lineno++;
		if (flag != -1)
			purse = tokenize(lineptr);
		for (j = 0; purse[j]; j++)
		{
			ptr = matchf(purse[j]);
			if (ptr)
			{
				if (check == 1)
				{
					ares = atoi(purse[j + 1]);
					if (ares !=  0)
						ptr(&head, ares);
					else
						_perror(purse[j], lineno, 2);
				}
				else
					ptr(&head, lineno);
			}
			else
				_perror(purse[j], lineno, 3);
		}
		fclose(fp);
		free(new);
		free(flag);
	}
return (0);
}

