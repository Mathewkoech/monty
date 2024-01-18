#include "monty.h"

/**
  * add -  adds the top two elements of the stack.
  * @stack: structure containing the stack
  * @line_number: line number of the opcode in the file
  */

void add(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (head->next->n) + (head->n);
	head->next->n = result;
	pop(stack, 0);
}
