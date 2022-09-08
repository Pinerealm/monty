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

/**
 * nop - does nothing
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the second top element of the stack by the top element
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n /= (*stack)->n;
	pop(stack, line_number);
}
