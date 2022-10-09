#include "monty.h"

/**
 * _pall - function to print all function
 * @stack: pointer to linked list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int num_line)
{
	stack_t *h;

	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
