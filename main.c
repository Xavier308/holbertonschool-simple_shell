#include "shell.h"

/**
 * main - This program implements a simple shell that reads commands from
 *              the user and executes them. It supports reading from the
 *              standard input and executing system commands. 
 *
 * Return: Returns 0 upon successful execution.
 */
int main(void)
{
	/* Variables declaration */
	char *cmd_buffer = NULL;
	size_t buf_size = 0;
	ssize_t line_size;
	char **args;

	/* Attempt to retrieve the PATH environment variable. */
	char *path_value = get_env_var("PATH");

	/* Check if the PATH environment variable is empty. */
	if (path_value == NULL || *path_value == '\0')
	{
		/* Default execution of the 'ls' command from the bin directory */
		/* If PATH is not set. */		
		char *ls_command[] = {"/bin/ls", NULL};

		execute_external(ls_command);
		return (0);
	}
	/* Infinite loop to keep the shell running */
	while (1)
	{
		display_prompt(); /* Displays the shell prompt to the user */

		/* Read a line of input from the user. */
		line_size = getline(&cmd_buffer, &buf_size, stdin);

		 /* Check for EOF (Ctrl+D) or read error. */
		if (line_size == -1)
			break;

		/* Parse the input into an array of strings (arguments). */
		args = parse_input(cmd_buffer);

		/* Execute the command if parsing was successful and a command was found. */
		if (args[0] != NULL)
			execute_command(args); /* Execute the command if not NULL */

		free_args(args); /* Free the memory allocated for arguments */
	}
	 /* Cleanup: free any remaining dynamically allocated memory. */
	free(cmd_buffer);

	return (0);
}
