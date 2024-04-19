#include "shell.h"

/**
 * execute_command - Executes a command using fork and execvp
 * after resolving the command path.
 *
 * @args: An array of strings where the first string is the command to execute
 * and the rest are its arguments.
 *
 * Description: This function first attempts to resolve the full path of
 * the command specified in args[0] using the find_in_path function,
 * which searches through the directories listed in the PATH
 * environment variable.
 *
 * Return: Returns 1 if the fork fails, otherwise returns 0 to indicate
 * successful execution or the termination of the command.
 * Also returns 0 if the command is not found in PATH,
 * with an appropriate error message being printed.
 */

int execute_command(char **args)
{
	pid_t pid; /* Process ID from fork */
	int status; /* Status of the child process */

	/* Find command in PATH  */
	char *cmd_path = find_in_path(args[0]);

	if (cmd_path != NULL)
	{
		pid = fork(); /* Create a new process */
		if (pid == 0) /* Child process */
		{
			/* Try to execute the command */
			if (execvp(args[0], args) == -1)
			{
			/* Change: Specific error */
			fprintf(stderr, "%s: Command not found\n", args[0]);
			exit(EXIT_FAILURE); /* Exit child process with failure status */
			}
		}
		else if (pid < 0) /* Check if fork failed */
		{
			perror("fork"); /* Print an error message if fork fails */
			return (1); /* Return 1 to indicate an error */
		}
		else /* Parent process */
		{
			/* Wait for the child process to terminate */
			do {
				waitpid(pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		free(cmd_path); /* Free the path found by find_in_path */
	}
	else
	{
		/* Command not found in PATH */
		fprintf(stderr, "%s: Command not found\n", args[0]);
	}

	return (0);
}
