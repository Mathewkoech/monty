#include "monty.h"

/**
 *_mul-multiplies the second top element of the
 *stack with the top element of the stack
 *@stack: pointer to top of stock
 *@line_number:line number
 *Return: modified stack
 */
stack_t *_mul(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *head = *stack;

	if (!head || !head->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = head->next->n * head->n;
	head->next->n = result;
	pop(stack, 0);
	return (*stack);
}
