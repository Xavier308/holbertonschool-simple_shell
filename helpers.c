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
	free(args); /* Free the memory allocated for the array of arguments */
}
