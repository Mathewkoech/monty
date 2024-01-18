#include "monty.h"
/**
 * opcode_ -searches operator executes operation
 * @p:operator argument to program
 * @stack: The pointer to the stack
 * @line_number: The line number in the file
 * Return: Return corresponding pointer to the operator
 */
stack_t *(*opcode_(char *p, stack_t **stack, unsigned int line_number))(stack_t
**stack, unsigned int line_number)
{
	instruction_t functs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"div", _div},
		{"sub", sub},
		{"add", add},
		{"mul", _mul},
		{"swap", swap},
		{"mod", mod},
		{"rotl", rotl},
		{"rotr", rotr},
		{"NULL", NULL}
	};
	char *opcode;
	int i = 0;

	while (i < (int)(sizeof(functs) / sizeof(instruction_t)))
	{
		opcode = (functs[i]).opcode;
		if (strcmp(p, opcode) == 0)
		{
			return (*(functs[i]).f);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, p);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
