#include "monty.h"

/**
 * _rotl -  rotates at the top of the stack
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _rotl(stack_t **stack, unsigned int num_line)
{
	stack_t *h;
	int rot = 0;

	h = *stack;
	if (!num_line || !stack || !(*stack)->next)
		return;
	rot = h->n;
	while (h->next)
	{
		h = h->next;
		h->prev->n = h->n;
	}
	h->n = rot;
}
