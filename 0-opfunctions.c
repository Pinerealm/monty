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
	{
		fprintf(stderr, "Error: malloc failed\n");
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	token = strtok(NULL, " \n\t");
	if (token == NULL || is_number(token) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(new);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(token);
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
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
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}
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
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		cleanup(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}
