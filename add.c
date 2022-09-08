#include "monty.h"

/**
 * add - adds the top two elements of the stack
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	pop(stack, line_number);
}
