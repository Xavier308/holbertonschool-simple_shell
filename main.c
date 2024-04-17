#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Description: This is a simple shell program
 *
 * Return: (0) on successful execution.
 */
int main(void)
{
	/* Variables declaration */
	char *cmd_buffer = NULL;
	size_t buf_size = 0;
	ssize_t line_size;
	char **args;

	/* Infinite loop to keep the shell running */
	while (1)
	{
		display_prompt(); /* Display command prompt */

		/* Read line from stdin */
		line_size = getline(&cmd_buffer, &buf_size, stdin);

		/* Check for end of file (no input) */
		if (line_size == -1)
			break;

		/* Parse the input string into commands and arguments */
		args = parse_input(cmd_buffer);
		if (args[0] != NULL)
			execute_command(args); /* Execute the command if not NULL */

		free_args(args); /* Free the memory allocated for arguments */
	}

	free(cmd_buffer); /* Free the buffer allocated for command input */
	return (0); /* Return zero to indicate successful execution */
}

