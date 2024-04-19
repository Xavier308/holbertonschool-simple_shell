#include "shell.h"

/**
 * find_in_path - Searches for a command in the system's PATH.
 * @cmd: The command to search for.
 *
 * Description: This function attempts to locate the given command in the
 * directories specified by the PATH environment variable. It iterates over
 * each directory in PATH, constructs a potential path for the command,
 * and checks if a file at that path exists and is executable.
 *
 * Return: A pointer to a dynamically allocated string if found;
 * otherwise, NULL.
 */

char *find_in_path(char *cmd)
{
	char *path = getenv("PATH");
	/* Make a copy because strtok modifies the string */
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	struct stat st;

	while (dir != NULL)
	{
		/* +2 for '/' and '\0' */
		char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);

		sprintf(full_path, "%s/%s", dir, cmd);

		/*  Check if the file exists and is executable */
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL); /*  Command not found in any PATH directory */
}

