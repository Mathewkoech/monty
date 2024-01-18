#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @stack: stack head
 * @line_number: line_number
 * Return: return
*/
stack_t *pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	(void)line_number;

	while (head)
	{
		if (head->n < 32 || head->n > 127)
			break;
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');

	return (*stack);
}
