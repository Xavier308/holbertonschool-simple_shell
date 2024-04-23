#include "shell.h"

/**
 * handle_builtins - Handles execution of built-in shell commands.
 * @args: An array of strings representing command arguments.
 *
 * Description: This function checks the command name in args[0] and
 * executes it if it's a built-in command like 'cd' or 'exit'. It changes
 * the working directory for 'cd' or exits the shell for 'exit'.
 * Return: 0 if a built-in command was handled, 1 otherwise.
 */
int handle_builtins(char **args)
{
	if (strcmp(args[0], "cd") == 0)
	{
		return (0);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0); /* Exit the shell when 'exit' is typed */
	}
	else if (strcmp(args[0], "pwd") == 0)
	{
		char cwd[PATH_MAX];

		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printf("%s\n", cwd);
		}
		else
		{
			perror("pwd");
		}
		return (0);
		}
	return (1);
}

