#include "monty.h"

/**
 * cleanup - frees a stack_t stack
 * @stack: the stack
 *
 * Return: void
 */
void cleanup(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(g.line);
	if (g.file)
		fclose(g.file);
}
