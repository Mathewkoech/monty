#include "monty.h"

/**
 *rotr- rotates the stack to the bottom.
 *@stack: pointer to top stack
 *@line_number: line number
 *Return:pointer to new stack
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *temp1 = NULL;
	(void)line_number;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	temp = (*stack)->next;
	temp1 = *stack;

	for (; temp1->next != NULL; temp1 = temp1->next)
		;

	temp->prev = NULL;
	temp1->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = temp1;
	*stack = temp;
}
