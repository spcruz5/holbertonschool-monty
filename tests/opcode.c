#include "monty.h"

/**
 * _push - pushes elem to stack
 * @stack: double ptr to stack
 * @line_number: line num
 * Return: void
*/
/*void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = line_number;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}*/

void _push(stack_t **head, unsigned int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (!*head)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}



/**
 * print_stack - print ele of a doubly linked list
 * @h: ptr to the head node of list
 * Return: num of nodes
 */
size_t print_stack(const stack_t *h)
{
    int i;

    if (h == NULL)
        return (0);
    for (i = 0; h; i++, h = h->next)
        printf("%d\n", h->n);
    return (i);
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
