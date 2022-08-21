#include "monty.h"

/**
 * _push - pushes elem to stack
 * @stack: double ptr to stack
 * @num: line num * Return: void
*/
void _push(stack_t **stack, unsigned int num)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_dlist(*stack);
		exit(EXIT_FAILURE);
	}

	newNode->next = *stack;
	newNode->prev = NULL;
	newNode->n = num;

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
	stack_t *current =  *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
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
