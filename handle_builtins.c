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
		/* Use HOME if no argument is given  */
		char *dir = args[1] ? args[1] : getenv("HOME");

		if (dir == NULL || chdir(dir) != 0)
		{
			perror("cd failed");  /* Print why the cd failed */
		}
		return (0);  /* Command handled */
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0); /* Exit the shell cleanly */
	}
	return (1); /* Indicate no built-in command was handled */
}

