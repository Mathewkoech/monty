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
	while (!head)
	{
		head = head->next;
	}
	*stack = (*stack)->next;
	head->next = (*stack)->prev;
	(*stack)->prev = NULL;
	head->next->prev = head;
	head = head->next;
	head->next = NULL;
}
