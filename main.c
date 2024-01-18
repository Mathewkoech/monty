#include "monty.h"
/**
* main - Interprets bytecode
* @argc: number of arguments
* @argv: array of arguments
* Return: 0 on success
*/
int element = 1;

#define MAX_LINE_LEN 100

int main(int argc, char *argv[])
{
	FILE *file;
	char line[MAX_LINE_LEN];
	size_t line_len = 0;
	char *opcode, *str;
	stack_t *stack = NULL;
	unsigned int line_number = 0, i = 0;

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
		if (strcmp(opcode, "push") == 0)
		{
			str = strtok(NULL, " $\t\n");
			if (str == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			if (str[0] == '-' && str[1] != '\0')
				i = 1;
			for (; str[i] != '\0'; i++)
			{
				if (isdigit(str[i]) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
			element = atoi(str);
		}
		opcode_(opcode, &stack, line_number)(&stack, line_number);
			}
	fclose(file);
	return (0);
}
