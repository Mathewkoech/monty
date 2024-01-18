#include "monty.h"

/**
  * add -  adds the top two elements of the stack.
  * @stack: structure containing the stack
  * @line_number: line number of the opcode in the file
  */

void add(stack_t **stack, unsigned int line_number)
{
	int i = 1;
	stack_t *temp;

	while ((*stack)->next != NULL)
		i++;

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (stack_t *) malloc(sizeof(stack_t *));

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;

	free(temp);
}

