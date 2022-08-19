#include "monty.h"

/**
 * _push - pushes elem to stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = ///to head
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * _pall - print element of stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}

/**
 * _pint - prints top val of stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}





/**
 * _nop - nothing
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
