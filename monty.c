#include "monty.h"
global_t g = {"stack", NULL, NULL};

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Description: Entry point for the monty interpreter
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	char *token;
	ssize_t read;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	g.file = fopen(argv[1], "r");
	if (g.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&g.line, &len, g.file)) != -1)
	{
		line_number++;
		token = strtok(g.line, " \n\t");
		if (token == NULL || token[0] == '#')
			token = "nop";
		exec_opcode(&stack, &line_number, token);
	}
	cleanup(stack);

	return (EXIT_SUCCESS);
}
