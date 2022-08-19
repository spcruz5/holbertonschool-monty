#include "monty.h"


void _perror(char *str, int lineno, int errtype)
{
	if (errtype == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	if (errtype == 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (errtype == 3)
	{
		fprintf(stderr, "L%d: unknown instruction\n", lineno);
		exit(EXIT_FAILURE);
	}
}
