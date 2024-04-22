#include "shell.h"
#include <errno.h>

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

int execute_command(char **args, const char *program_name)
{
    if (handle_builtins(args) == 0) 
    {
        return (0); /* Built-in command was executed, return immediately */
    }
    return execute_external(args, program_name); /* Handle external commands */
}


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
int execute_external(char **args, const char *program_name)
{
    pid_t pid;
    int status;
    char *cmd_path;

    cmd_path = args[0][0] != '/' ? find_in_path(args[0]) : strdup(args[0]);

    if (cmd_path == NULL)
    {	
	/* removed 'command' y se puso un 1 */ 
        fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);	
        return (1); /* Command not found */
    }

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
	/* printf("Executing command: %s\n", cmd_path);  ---for depuration--- */
        execvp(cmd_path, args);
        fprintf(stderr, "%s: failed to execute - %s\n", cmd_path, strerror(errno));
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("fork failed");
        free(cmd_path);
        return (2);
    }
    else
    {
        /* Parent process, wait for the child to terminate */
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
	{
            fprintf(stderr, "Command exited with status %d\n", WEXITSTATUS(status));
	    free(cmd_path);
	    return  (2); /* changed from 2 to 3 */
        }
    }

    free(cmd_path);
    return (0);
}

