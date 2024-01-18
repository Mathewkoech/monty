#include "monty.h"

/**
  * executeInstruction
  * @stack
  * @instructions
  * @numInstructions
  * @opcode
  * @line_number
  */

void executeInstruction(stack_t **stack, instruction_t *instructions, size_t numInstructions, char *opcode, unsigned int line_number, char *file_line)
{
	size_t i;

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number, file_line);
		return;
	}

	for (i = 0; i < numInstructions; ++i)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

}

/**
  * execute_linecmd - function to check whether command is a builtin cmd
  * @stack: command to be checked
  * @line_number: line number of the current file_line
  * @file_line: opcode line in the file
  */

void get_instruction(stack_t **stack, unsigned int line_number, char *file_line)
{
	char opcode[20];
/*	char *my_command, *delim = " \t";*/
	size_t numInstructions;
/*	unsigned int i = 0;*/
	/*int element;*/
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		/*{NULL, NULL}*/
	};

	/*extract opcode from file_line*/
	if (sscanf(file_line, "%s", opcode) != 1)
	{
		fprintf(stderr, "Error parsing opcode at line %u", line_number);
		exit(EXIT_FAILURE);
	}

	/*Execute instruction based on opcode*/

	numInstructions = sizeof(instructions) / sizeof(instruction_t);

	executeInstruction(stack, instructions, numInstructions, opcode, line_number, file_line);
}
