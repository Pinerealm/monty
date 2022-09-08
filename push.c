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

