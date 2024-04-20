#include "shell.h"
#include <unistd.h>

/**
 * get_env_var - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if not found.
 */

/* Retrieves the value of an environment variable */
char *get_env_var(const char *name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
		    environ[i][strlen(name)] == '=')
		{
			return (&environ[i][strlen(name) + 1]);
		}
	}
	return (NULL);
}

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

/* Searches for a command in the system's PATH */
char *find_in_path(char *cmd)
{
	char *path = get_env_var("PATH");
	char *path_copy, *dir;
	struct stat st;

	if (!path)
	{
		return (NULL); /* PATH not found */
	}

	path_copy = strdup(path);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);

		sprintf(full_path, "%s/%s", dir, cmd);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
