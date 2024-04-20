#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h> /* used in find_in_path */

#define MAX_ARGS 10

#define CRITICAL_ERROR 1 /* for hadling_error */

extern char **environ; /* eviron global, for path */

/*  Function prototypes */
void display_prompt(void);
char **parse_input(char *input);
int execute_command(char **args);
void free_args(char **args);
/**
 * find_in_path - Searches the system's PATH to find an executable file.
 * @cmd: The command name to search for.
 *
 * Description: This function attempts to locate the command specified by `cmd`
 * in the directories listed in the system's PATH environment variable.
 * It checks each directory to see if it contains
 * an executable file named `cmd`.
 *
 * Return: A pointer to a dynamically allocated string containing the full path
 * to the executable if found; otherwise, NULL.
 */
char *find_in_path(char *cmd);

/* Handle built-in commands like cd and exit */
int handle_builtins(char **args);

/* Execute external commands found in PATH */
int execute_external(char **args);

/* Error handling function */
void handle_error(const char *error_message, int error_code);

#endif

