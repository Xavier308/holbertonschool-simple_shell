#include "shell.h"

/**
 * free_args - Frees the memory allocated for the command arguments.
 * @args: An array of strings representing the command and its arguments.
 *
 * Description: This function is responsible for freeing the memory allocated
 * for the array of command arguments that was previously allocated during
 * the parsing process. Critical step in managing memory to avoid
 * memory leaks.
 */
void free_args(char **args)
{
	if (args != NULL)
	{
		int i = 0;

		while (args[i] != NULL)
		{
			free(args[i]); /* Free each argument string */
			i++;
		}
		free(args); /* Free the array of pointers */
	}
}

/**
 * handle_error - Prints a formatted error message indicating a
 * command was not found.
 *
 * @program_name: Generic name of the shell program.
 * @error_code: The error code that determines the action to be taken.
 * @error_message: The error message ***Descript need more inprovement **
 *
 * Description: This function is called when an error occurs related to an
 * unrecognized command.
 * It formats an error message including the program name and the command.
 * This helps to align the shell's error reporting with that of standard
 * shells like /bin/sh.
 */
void handle_error(const char *program_name, const char *error_message,
			int error_code)
{
	if (error_code == CRITICAL_ERROR)
	{
		fprintf(stderr, "%s: 1: %s: Command not found\n",
				program_name,
				error_message);
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stderr, "%s: Error: %s\n", program_name, error_message);
	}
}
