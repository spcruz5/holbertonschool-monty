#include "monty.h"

/**
 * matchf - matches opcode with function 
 * @opc - opcode
 *
 * Return: NULL
 */

int (*matchf(const char *opc))(stack_t, unsigned int)
{
	int i, j;
	instruction_t fmt[] = {
		{'push', _push},
		{'pall', _pall},
		{'\0', NULL}
	};

	for (i = 0; fmt[i].opcode; i++)
	{
		if (strcmp(fmt[i].opcode, opc)  == 0)
		{
			if (i == 0)
				check = 1;
			return (fmt[i].f);
		}
	}
	return (NULL);
}
