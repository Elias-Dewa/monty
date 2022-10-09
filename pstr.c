#include "monty.h"

/**
 * _pstr -  prints the string starting at the top of the stack
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _pstr(stack_t **stack, unsigned int num_line)
{
	stack_t *h;
	int i = 0;


	h = *stack;

	while (h)
	{
		i = h->n;
		if (i == 0)
			break;
		putchar(i);
		h = h->next;
	}
	puchar('\n');
}
