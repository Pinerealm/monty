#include "monty.h"

/**
 * exec_bcode - executes the bytecode
 * @stack: stack address
 * @line_number: line number address where the program is
 * @token: current instruction
 *
 * Return: void
 */
void exec_bcode(stack_t **stack, unsigned int *line_number, char *token)
{
	int i;
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, *line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
