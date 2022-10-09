#include "monty.h"

/**
 * _add - function to add on the top of stack
 * @stack: pointer of linked list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int num_line)
{
	stack_t *h;
	int len = 0, sum = 0;

	h = *stack;
	while (!h)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	while (h)
	{
		h = h->next;
		len++;
	}

	if (stack == NULL || (*stack)->next == NULL || len <= 1)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->next->n + (*stack)->n;
	_pop(stack, num_line);
	(*stack)->n = sum;
}
