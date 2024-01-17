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
	char nline, *file_line = NULL;
	size_t fLine_len = 0;
	ssize_t char_read;

	/*stack_t *stack = NULL;*/
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
	char_read = getline(&file_line, &fLine_len, file);

	/*Loop through till we are done with the file*/
	while (char_read >= 0)
	{
		lines += 1;

		/*program to execute the commands from opfile: HERE*/

		/*go to the next line*/
		char_read = getline(&file_line, &fLine_len, file);
	}

	free(file_line);
	file_line = NULL;

	fclose(file);

	return (0);
}
