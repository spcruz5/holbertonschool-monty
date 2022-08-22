#include "monty.h"

/**
 * pop - deletes the top ele of stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmpint;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmpint = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmpint;
}

/**
 * add - adds the top two elements of the stack and pops the first one
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub - subs the top two elements of the stack and pops the first one
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n - (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - muls the top two elements of the stack and pops the first one
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = ((*stack)->n) * ((*stack)->prev->n);
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
