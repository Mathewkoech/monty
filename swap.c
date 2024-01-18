#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: ponter to the list stack
 * @line_number: line number
 * Return: Returns address of the first node
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
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
