#include "shell.h"

/**
  * builtin_cmd - function to check whether command is a builtin cmd
  * @my_command: command to be checked
  * Return: 0
  */

stack_t *execute_linecmd(stack_t **stack, unsigned int line_number)
{
	char *builtins[] = {
		{"push"},
		{"pall", pall(stack, line_number)},
		{"pint", pint(stack, line_number)},
		{"pop", pop(stack, line_number)},
		{"swap", pop(stack, line_number)},
		{"add", pop(stack, line_number)},
		{"nop"},
	};
	char *my_command, *delim = " \t";
	int i;

	my_command = strtok(file_line, delim);

	for (i = 0; builtins[i]; i++)
	{
		if (my_command == "push" && strcmp(my_command, builtins[i]) == 0)
		{
			element = strtok(NULL, delim);
			push(stack, lines, element);
		}
		else if (strcmp(my_command, builtins[i]) == 0)
		{
			return (builtin[i][1]);
		}

	}
	return (0);
}
