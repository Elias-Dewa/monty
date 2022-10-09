#include "monty.h"

/**
 * _rotr -  rotates the stack to bottom
 * @stack: pointer to list
 * @num_line: number of line
 *
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int num_line)
{
        stack_t *h;
        int rot = 0;

        h = *stack;
        if (!num_line || !stack || !(*stack)->next)
                return;
	while (h->next)
		h = h->next;
        rot = h->n;
        while (h->prev)
        {
                h = h->prev;
                h->next->n = h->n;
        }
        h->n = rot;
}
