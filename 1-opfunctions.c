#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	*stack = tmp;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element from the second top element of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	*stack = tmp;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * divide - divides the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	tmp->n /= (*stack)->n;
	*stack = tmp;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - divides the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	*stack = tmp;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
