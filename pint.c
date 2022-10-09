#include "monty.h"

/**
 * _pint - function to print a head of stack
 * @stack: pointer to linked list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int num_line)
{
	stack_t *h;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", h->n);
}
