#include "monty.h"
/**
 * mod - This function computes the rest of the division of the
 * second top element of the stack by the top element of the stack
 * @stack: The pointer to the stack
 * @line_number: The current line number in the file
 * Return: The pointer to the stack
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int result = 0;

	if (!head || !(head->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	result = (head->next->n) % (head->n);
	head->next->n = result;
	pop(stack, 0);
}
