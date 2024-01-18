#include "monty.h"

/**
  * sub -  sbtracts the top element from the second of the stack.
  * @stack: structure containing the stack
  * @line_number: line number of the opcode in the file
  */

void sub(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		/* Print error, free, and exit */
		fprintf(stderr, "L%d: can't sub, stack too short\n",
line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	diff = (head->next->n) - (head->n);
	head->next->n = diff;
	pop(stack, 0);
}
