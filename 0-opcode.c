#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *token = NULL;
	int n;

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, " \n\t");
	if (token == NULL || is_number(token) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;

}

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

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: the stack address
 * @line_number: the current line number
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = (*stack)->prev;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = tmp;
}
