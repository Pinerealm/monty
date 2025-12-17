#include "monty.h"
#include <stdarg.h>

/**
 * err - prints error message, frees stack and exits
 * @stack: pointer to the stack
 * @fmt: format string
 *
 * Return: void
 */
void err(stack_t **stack, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);

	if (stack)
		cleanup(*stack);
	exit(EXIT_FAILURE);
}
