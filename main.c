#include "monty.h"

/**
 * main - Interprets bytecode
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char file_line[100];
	size_t line_len = 0;
	unsigned int lines = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*open bytecode file*/
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Program to count the Number of Lines and get the line in the Text File */
	/*Loop through till we are done with the file*/

	while (fgets(file_line, sizeof(file_line), file) != NULL)
	{
		++lines;
		/*Remove newline character from the end of the line*/
		line_len = strlen(file_line);
		if (line_len > 0 && (file_line[line_len - 1] == '\n'))
			file_line[line_len - 1] = '\0';

		get_instruction(&stack, lines, file_line);
	}

	fclose(file);

	return (0);
}
