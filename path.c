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
    char *path_copy, *dir, *full_path = NULL;
    struct stat st;

    printf("Current PATH: %s\n", path);
    
    if (!path) 
	{
	    return (NULL);
	 }

    path_copy = strdup(path);

    if (!path_copy) 
    {    
	    return (NULL);
}
    for (dir = strtok(path_copy, ":"); dir != NULL; dir = strtok(NULL, ":"))
    {
        full_path = malloc(strlen(dir) + strlen(cmd) + 2);
        if (full_path == NULL) {
            free(path_copy);
            return (NULL);
        }
        sprintf(full_path, "%s/%s", dir, cmd);
	printf("Checking path: %s\n", full_path); /*  for depuration */
        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR)) {
           free(path_copy);
            return (full_path);
        }
        free(full_path);
        full_path = NULL;
    }

    free(path_copy);
    return (NULL);
}

