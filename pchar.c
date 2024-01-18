#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: stack
 * @line_number: The line number of the file
 * Return:head of the stack
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr,
			"L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(temp->n);
	putchar('\n');
}
