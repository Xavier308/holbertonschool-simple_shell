#include "shell.h"

/**
 * execute_command - Executes a command using fork and execvp.
 * @args: An array of strings where the first string is the command to execute
 *        and the rest are its arguments.
 *
 * Description: This function forks the current process to create a new child
 * process. The child process then attempts to execute the command specified
 * in args[0] with execvp. If execvp fails, a specific error message is printed
 * and the child process exits.
 * The parent process waits for the child to terminate.
 *
 * Return: Returns 1 if the fork fails, otherwise returns 0 to indicate
 *         successful execution or the termination of the command.
 */
int execute_command(char **args)
{
	pid_t pid; /* Process ID from fork */
	int status; /* Status of the child process */

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

	return (0); /* Return 0 to indicate successful execution */
}

