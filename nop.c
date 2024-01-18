#include "monty.h"

/**
 *nop- program that does nothing
 *@line_number:line number for instructions
 *@stack:pointer to top of stack
 *Return: returns pointer to stack
 */
stack_t *nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	return (0);
}