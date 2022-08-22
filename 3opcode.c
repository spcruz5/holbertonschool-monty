#include "monty.h"

/**
 * _div - divs the top two elements of the stack and pops the first one
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n) / ((*stack)->prev->n);
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
