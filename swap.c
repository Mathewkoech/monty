#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: ponter to the list stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head;
	int temp;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		/*free_stack(stack);*/
		/*exit(EXIT_FAILURE);*/
	}

	head = *stack;
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;

}
