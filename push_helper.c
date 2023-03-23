#include "monty.h"

/**
 * stack_push - pushes an element to the stack
 * @stack: current stack
 * @new: new node to push
 */
void stack_push(stack_t **stack, stack_t *new)
{
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * queue_push - pushes an element to the queue
 * @stack: current stack
 * @new: new node to push
 */
void queue_push(stack_t **stack, stack_t *new)
{
	stack_t *tmp = *stack;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
}
