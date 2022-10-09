#include "monty.h"

/**
 * _sub - function to sub on the top of stack
 * @stack: pointer of a list
 * @num_line: number of a line
 *
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int num_line)
{
	stack_t *h;
	int len = 0, sub = 0;

	h = *stack;
	if (!h)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	while (h)
	{
		h = h->next;
		len++;
	}
	if (stack == NULL || (*stack)->next == NULL || len <= 1)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, num_line);
	(*stack)->n = sub;

}
