#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 *
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		return;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
