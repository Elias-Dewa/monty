#include "monty.h"

/**
 * _swap - function to swap top of stack
 * @stack: pointer to linked list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int num_line)
{
	stack_t *h;
	int temp;

	h = *stack;
	if (h == NULL || h->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	temp = h->n;
	h->n = h->next->n;
	h->next->n = temp;
}
