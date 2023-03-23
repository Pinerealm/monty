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
/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - make the top element of the stack the last one, and the second
 * top element of the stack the first one
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
