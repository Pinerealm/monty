#include "monty.h"

/**
 * exec_opcode - execute the bytecode
 * @stack: pointer to the stack
 * @line_number: pointer to the current line number
 * @opcode: the opcode to execute
 */
void exec_opcode(stack_t **stack, unsigned int *line_number, char *opcode)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, *line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, opcode);
	free_stack(*stack);
	free(line);

	exit(EXIT_FAILURE);
}
