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
	/* Loop through each environment variable available in environ */
	for (i = 0; environ[i] != NULL; i++)
	{
	/* Check if the current environment variable starts with 'name' followed by '=' */	
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
		    environ[i][strlen(name)] == '=')
		{
			/* Return a pointer to the value part of the environment variable */
			return (&environ[i][strlen(name) + 1]);
		}
	}
	/* Return NULL if the environment variable 'name' was not found */
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

	/* Handle the case where PATH environment variable is not found */
	if (!path)
	{
		return (NULL); /* PATH not found */
	}

	/* Duplicate PATH to modify it safely */
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		return (NULL); /* If memory allocation failed, return NULL */
	}

	/* Split the PATH variable into directories using ':' as delimiter */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		/* Allocate memory for full path of command */
		char *full_path = malloc(strlen(dir) + strlen(cmd) + 2);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL); /* Return NULL if memory allocation fails */
		}
		/* Construct the full path of the command */
		sprintf(full_path, "%s/%s", dir, cmd);

		/* Check if the command exists and is executable */
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			/* Return the full path if command is found and executable */
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":"); /* Continue with next directory in PATH */
	}

	free(path_copy);
	return (NULL); /* Command not found in any PATH directory */
}

