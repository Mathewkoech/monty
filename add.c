#include "monty.h"

/**
*add-adds the top two elements of the stack.
*@stack:pointer to top stack
*@line_number:line number with instructions
*Return: pointer
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

	return (*stack);
}
