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
	unsigned int line_number = 0;
	stack_t *stack = NULL;

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
		exec_bcode(&stack, &line_number, token);
	}
	free_stack(stack);
	free(line);
	fclose(fp);

	return (0);
}
