#include "monty.h"

/**
 * rotl - rotate the stack to the top
 * @stack:pointer to the top of the stack
 * @line_number: The current line number in the file
 * Return:pointer to the stack
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;

	if (!head)
	{
		return;
	}

	/* Rotate the stack*/
	while (head->next)
	{
		head = head->next;
	}
	head->next = *stack;
	(*stack)->prev = head;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}
