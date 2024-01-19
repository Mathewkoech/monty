#include "monty.h"

/**
 * pop - Removes the element at the top of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number where the instruction appears
 * Return: the removed element
 */
stack_t *pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
		free_stack(stack);
	}

	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;

	free(temp);
}
