#include "monty.h"

/**
 * set_as_stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void set_as_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	if (strcmp(g.stack_format, "stack") != 0)
		g.stack_format = "stack";
}

/**
 * set_as_queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void set_as_queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	if (strcmp(g.stack_format, "queue") != 0)
		g.stack_format = "queue";
}
