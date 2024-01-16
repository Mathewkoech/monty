#include "monty.h"

/**
 * pall - prints all the values on the stack,
 *starting from the top of the stack
 * @stack: pointer to the top stack
 * @line_number:Line number
 * Return: the address of the first node
 */
stack_t *pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		return (NULL);
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		node++;
	}

	return (*stack);
}
