#include "monty.h"

/**
  * swap -  swaps the top two elements of the stack.
  * @stack: structure containing the stack
  * @line_number: line number of the opcode in the file
  */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int temp;

	(void)line_number;

	head = *stack;

	if (head != NULL || head->next != NULL)
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}
