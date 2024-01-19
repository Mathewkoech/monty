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

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: div, stack too short\n",
		       line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
