#include "shell.h"
#include <errno.h>

/**
 * execute_external - Executes external commands found in the PATH.
 * @args: An array of strings representing command arguments.
 *
 * Description: This function resolves the command's full path using
 * find_in_path if it's not provided as an absolute path. It then attempts
 * to execute the command using execvp. If the command doesn't exist or an
 * error occurs during execution, it handles errors appropriately.
 * Return: 0 on successful execution, 1 on failure.
 */
int execute_external(char **args)
{
	pid_t pid;
	int status;
	char *cmd_path;

	cmd_path = args[0][0] != '/' ? find_in_path(args[0]) : strdup(args[0]);

	if (cmd_path == NULL)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		return (1); /* Command not found */
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process  */
		execvp(cmd_path, args);

		/* If execvp returns, there was an error  */
		fprintf(stderr, "%s: failed to execute - %s\n", cmd_path, strerror(errno));
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork failed");
		free(cmd_path);
		return (1);
	}
	else
	{
		/*  Parent process, wait for the child to terminate */
		waitpid(pid, &status, 0);

		if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command exited with status %d\n", WEXITSTATUS(status));
		}
	}
	free(cmd_path);
	return (0);
}

