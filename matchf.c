#include "monty.h"

/**
 * matchf - matches opcode with function
 * @purse: purse of tokens
 * @lineptr: buffer to save line
 * @h: head of node
 * @fp: file stream
 * @lineno: line number
 * Return: Nothing
 */

void matchf(char **purse, char *lineptr, stack_t **h,
FILE *fp, unsigned int lineno)
{
	int i, flag = 0;
	char *cont = purse[1];
	instruction_t fmt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (strcmp(purse[0], "push")  == 0)
	{
		if (purse[1])
			flag = check_val(cont);
		if (!purse[1] || flag == 0)
		{
			free(purse);
			free(lineptr);
			free_dlist(*h);
			fclose(fp);
			_perror("void", lineno, 2);
		}
	}
	if (purse[1])
		lineno = atoi(purse[1]);
	for (i = 0; fmt[i].opcode != NULL; i++)
	{
		if (strcmp(fmt[i].opcode, purse[0])  == 0)
		{
			fmt[i].f(h, lineno);
			return;
		}
	}
	_perror(purse[0], lineno, 3);
}
