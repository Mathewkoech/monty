#include "monty.h"

/**
 *sub-subtracts the top element of the stack
 *from the second top element of the stack
 *@stack:pointer to top stack
 *@line_number:line number with instructions
 *Return: pointer
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
