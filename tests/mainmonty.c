#include "monty.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 if success.
 */

char **purse = NULL;
int check;

int main(int ac, char **av)
{
	stack_t *head = NULL;
	stack_t *new = NULL;
	unsigned int i, j, ares, lineno = 0;
	void (*ptr)(stack_t **, unsigned int);
	int flag;
	FILE *fp;
	char *lineptr = NULL;
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
	fp = fopen(av[1], "r");
	if (!fp)
		_perror(av[1], 0, 1);
	for (i = 0; flag != EOF; i++)
	{
		check = 0;
		lineptr = NULL;
		size = 0;
		flag = getline(&lineptr, &size, fp);
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
					{
						ptr(&head, ares);	
						break;
					}
					else
						_perror(purse[j], lineno, 2);
				}
				else
				{
					ptr(&head, lineno);
					break;
				}	
			}
			else
				_perror(purse[j], lineno, 3);
		}
	free(lineptr);
	}
	fclose(fp);
	free(new);
	return (0);
}
