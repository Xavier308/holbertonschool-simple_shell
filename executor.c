#include "shell.h"

/**
 * execute_command - Decides how to execute a command based on its type.
 * @args: An array of strings representing command arguments.
 *
 * Description: This function checks if a command is a built-in or external
 * command. It first tries to handle the command as a built-in. If it is not
 * handled as a built-in, the function proceeds to handle it as an external
 * command.
 * Return: 0 if the command is executed successfully, or 1 if an error occurs.
 */
int execute_command(char **args)
{
	if (handle_builtins(args) == 0)
	{
		return (0); /* Built-in command was executed, so we return immediately. */
	}
	return (execute_external(args)); /* Handle external commands. */
}

