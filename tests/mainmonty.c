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
	int i, j, fd, flag, ares, lineno = 0;
	int (*ptr)(stack_t, int);
	
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
	fd = open(av[1], O_RDONLY)
	if (fd == -1)
		_perror(av[1], NULL);
	for (i = 0; flag != EOF; i++)
	{
		flag = getline(&lineptr, &n, fd);
		lineno++;
		if (flag > 0)
			purse = tokenize(lineptr);
		for (j = 0; purse[j]; j++)
		{
			ptr = matchf(purse[j]);
			if (ptr)
			{
				if (check == 1)
				{
					ares = atoi(purse[j + 1]);
					if(ares !=  0)
						ptr(&head, ares);
					else
						_perror(purse[j], lineno);
				}
				else
					ptr(&head, lineno);
			}
			else
				_perror(purse[j], lineno);
		}
	}
return (0);
}

