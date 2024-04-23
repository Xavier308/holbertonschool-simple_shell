#include "shell.h"

/**
 * main - Entry point of the shell program.
 * Description: This is a simple shell program that
 * handles commands from stdin.
 *
 * @argc: Need description *****
 * @argv: Nedd description ****
 *
 * Return: Returns (0) on successful execution,
 * otherwise returns error code.
 */
int main(int argc, char **argv)
{
	char *cmd_buffer = NULL;
	size_t buf_size = 0;
	int is_interactive;
	/* int continue_running = 1; */

	/* Explicitly stating that argc is not used-for warning */
	(void)argc;

	is_interactive = isatty(STDIN_FILENO);


	while (1)
	{
		if (is_interactive) /* added new */
		{
			display_prompt();
		}

		if (process_command(argv[0], &cmd_buffer, &buf_size) == 0)
		{
			break;
		}
	}

	free(cmd_buffer);
	return (0);
}

/**
 * process_command - Processes each command input by the user.
 * @cmd_buffer: Pointer to the command buffer.
 * @buf_size: Pointer to the buffer size variable.
 * @program_name: Generic name for the shell program.
 *
 * Description: Reads a line from stdin and processes it
 * using various helper functions.
 *
 *  Return: Need description ***
 */
int process_command(const char *program_name, char **cmd_buffer,
		size_t *buf_size)
{
	ssize_t line_size;
	char **args;
	int result;

	line_size = getline(cmd_buffer, buf_size, stdin);

	if (line_size == -1)
	{
		/* comment this line if cause problem */
		clean_exit(*cmd_buffer, feof(stdin) ? 0 : 1);
	}

	args = parse_input(*cmd_buffer);
	if (!args || !args[0])
	{
		free_args(args);
		return (1); /* continue */
	}

	result = execute_command(args, program_name);
	free_args(args);

	return (result == 1 ? 0 : 1);
}

/**
 * clean_exit - Handles the cleanup operations and exits the shell.
 * @cmd_buffer: Pointer to the command buffer to free.
 * @status: Exit status to return.
 *
 * Description: Frees the command buffer and exits the shell with
 * the given status.
 */
void clean_exit(char *cmd_buffer, int status)
{
	if (status == 0)
	{
		printf("\n");
	}
	else
	{
		perror("Readline error");
	}
	free(cmd_buffer);
	exit(status);
}
