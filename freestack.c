#include "monty.h"

/**
 *free_stack- frees stack in linked list
 *@stack:pointer to head stack
 *Return:returns nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *head;
	stack_t *temp;

	head = *stack;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
