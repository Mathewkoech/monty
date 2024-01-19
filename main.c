#include "monty.h"

#define MAX_LINE_LEN 100
int element = 1;

/**
* main - Interprets bytecode
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LEN], *opcode;
	size_t line_len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Program to count the Number of Lines and get the line in the Text File */
	while (fgets(line, MAX_LINE_LEN, file) != NULL)
	{
		line_number++;
		line_len = strlen(line);
		if (line[line_len - 1] == '\n')
			line[line_len - 1] = '\0';
		if (line[0] == '\0')
			continue;
		opcode = strtok(line, " $\t\n");
		if (opcode == NULL)
			continue;
		if (opcode[0] == '#')
		{
			nop(&stack, line_number);
			continue;
		}
		opcode_push(opcode, file, line_number);
		opcode_(opcode, &stack, line_number);
	}
	fclose(file);
	free_stack(&stack);
	return (0);
}
