#include "monty.h"

/**
 * _push - function to push integer to stack
 * @stack: linked list
 * @num_line: number of line
 *
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int num_line)
{
	stack_t *head;
	(void)num_line;

	head = malloc(sizeof(stack_t));
	if (!head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	head->n = global.push_arg;
	head->next = *stack;
	head->prev = NULL;
	if (*stack)
		(*stack)->prev = head;
	*stack = head;
}
