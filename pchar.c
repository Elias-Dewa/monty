#include "monty.h"

/**
 * _pchar - function to print the ASCII value
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int num_line)
{
	int value;

	if (!stack || (!*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack too short\n", num_line);
		free(global.buffer);
		fclose(global.file);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;
	if (value > 127 || value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack too short\n", num_line);
		free(global.buffer);
		fclose(global.file);
		free_all(*stack);
		exit(EXIT_FAILURE);
	}
	putchar(value);
	putchar('\n');
}
