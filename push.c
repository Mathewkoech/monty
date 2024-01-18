#include "monty.h"

/**
 * push - pushes element into stack
 * @stack: ponter to the top of stack
 * @line_number: line number of the opcode
 * @file_line: line of opcode in file
 */
void push(stack_t **stack, unsigned int line_number, char *file_line)
{
	const char err_message[] = "Error: malloc failed";
	stack_t *newnode;
	int element;
	char *opcode = strtok(file_line, " \t");

	element = atoi(strtok(NULL, " $\t\n"));
	if (element >= 0 || element < 0)
	{
		/* Create new node */
		newnode = malloc(sizeof(stack_t));
		if (newnode == NULL)
		{
			fprintf(stderr, err_message);
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
		free(opcode);
	}

	else
	{
		free(opcode);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}
