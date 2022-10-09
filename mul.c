#include "monty.h"

/**
 * _mul - function to mul top of stack
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int num_line)
{
	int mult;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_line);
		free(global.buffer);
		fclose(global.file);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mult = (*stack)->n;
		_pop(stack, num_line);
		(*stack)->n *= mult;
	}
}
