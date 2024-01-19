#include "monty.h"

/**
 *_div-subtracts the top element of the stack
 *from the second top element of the stack
 *@stack:pointer to top stack
 *@line_number:line number with instructions
 *Return: pointer
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	stack_t *head = *stack;

	/**stack = head;*/

	if (!head || !head->next)
	{
		fprintf(stderr, "L%u: div, stack too short\n",
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
	result = (head->next->n) / (head->n);
	head->next->n = result;

	pop(stack, 0);
}
