#include "monty.h"

/**
 *rotr- rotates the stack to the bottom.
 *@stack: pointer to top stack
 *@line_number: line number
 *Return:pointer to new stack
 */

stack_t *rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	
	(void)line_number;

	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
	return (*stack);
}
