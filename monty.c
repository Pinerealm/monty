#include "monty.h"

/**
 * main - the main monty interpreter
 *
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 *  Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0, i;
	stack_t *stack = NULL;
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t");
		if (token == NULL || token[0] == '#')
			continue;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(token, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: ", line_number);
			fprintf(stderr, "unknown instruction %s\n", token);
			free_stack(stack);
			free(line);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(stack);
	free(line);
	fclose(fp);

	return (0);
}
