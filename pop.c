#include "monty.h"

/**
 * _pop - function to remove element from a list
 * @stack: pointer of linked list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int num_line)
{
	stack_t *h;

	h = *stack;
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	*stack = h->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(h);
}
