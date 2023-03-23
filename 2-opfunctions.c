#include "monty.h"

/**
 * mod -  computes the rest of the division of the second top 
 * element of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n %= (*stack)->n;
	*stack = tmp;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
