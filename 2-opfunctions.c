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
		err(stack, "L%d: can't mod, stack too short\n", line_number);
	if ((*stack)->n == 0)
		err(stack, "L%d: division by zero\n", line_number);
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
		err(stack, "L%d: can't pchar, stack empty\n", line_number);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		err(stack, "L%d: can't pchar, value out of range\n", line_number);
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
	stack_t *first, *last;

	(void)line_number;
	if (!stack || !(*stack) || !(*stack)->next)
		return;

	first = last = *stack;
	while (last->next)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/**
 * rotr - make the last element of the stack the top element
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (!stack || !(*stack) || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}
