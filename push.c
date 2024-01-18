#include "monty.h"
/**
 *push - pushes element into stack
 *@stack: ponter to the top of stack
 *@element: element to push
 *@line_number: line number where intructions appear
 */

push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode;

	(void)line_number;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	/* Initialize the new node with the value of element*/
	newnode->n = element;
    /* New node is placed at the beginning of the list */
	newnode->prev = NULL;
	newnode->next = *stack;
    /* If new node is not alone, update the following one */
	if (*stack != NULL)
	{
		(*stack)->prev = newnode;
	}
	*stack = newnode;
}
