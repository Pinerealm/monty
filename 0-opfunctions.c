#include "monty.h"

/**
 * push - pushes a stack_t node onto the stack
 * @stack: pointer to the stack
 * @line_number: the present line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *token;
	int n;

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		err(stack, "Error: malloc failed\n");

	token = strtok(NULL, " \n\t");
	if (token == NULL || is_number(token) == 0)
	{
		free(new);
		err(stack, "L%d: usage: push integer\n", line_number);
	}
	n = atoi(token);
	new->n = n;
	if (strcmp(g.stack_format, "stack") == 0)
		stack_push(stack, new);
	else
		queue_push(stack, new);
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (stack == NULL)
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * followed by a new line
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err(stack, "L%d: can't pint, stack empty\n", line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		err(stack, "L%d: can't pop an empty stack\n", line_number);

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (!stack || !(*stack) || !(*stack)->next)
		err(stack, "L%d: can't swap, stack too short\n", line_number);
	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}
