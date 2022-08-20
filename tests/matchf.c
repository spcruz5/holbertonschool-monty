#include "monty.h"
#include <string.h>

/**
 * matchf - matches opcode with function 
 * @opc - opcode
 *
 * Return: NULL
 */

void (*matchf(const char *opc))(stack_t **, unsigned int)
{
	extern int check;
	int i;
	instruction_t fmt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"nop", _nop},
		{'\0', NULL}
	};
	for (i = 0; i < 4; i++)
	{
		printf("%ld\n", strlen(fmt[i].opcode));
		if (strcmp(fmt[i].opcode, opc)  == 0)
		{
			if (i == 0)
				check = 1;
			return (fmt[i].f);
		}
	}
	return (NULL);
}
