#include "monty.h"

/**
* opcode_push - Interprets bytecode
* @opcode: number of arguments
* @file: 0 on success
* @line_number: opcode line number
*/

void opcode_push(char *opcode, FILE *file, unsigned int line_number)
{
	char *str;
	int i = 0;

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
}
