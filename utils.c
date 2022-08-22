#include "monty.h"


/**
 * _perror - handles errors in the code
 * @filename: name of filein error
 * @lineno: line number the error was foun in
 * @errtype: typ of error
 * Return: Nothing
 */

void _perror(char *filename, int lineno, int errtype)
{
	if (errtype == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (errtype == 1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	if (errtype == 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineno);
		exit(EXIT_FAILURE);
	}
	if (errtype == 3)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineno, filename);
		exit(EXIT_FAILURE);
	}
}


/**
 * free_dlist - frees a list
 * @head: head of list
 * Return: Nothing
 */

void free_dlist(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * check_val - checks if the string is valid input
 * @str: string to be checked
 * Return: 0 if not valid, greater than 0 otherwise
 */

int check_val(char *str)
{
	int i = 0, val = 0;

	if (str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		val = isdigit(str[i]);
		if (val == 0)
			break;
	}
return (val);
}

