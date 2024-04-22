#include "shell.h"

/**
 * parse_input - Parses the input string into command and arguments.
 * @input: The input string entered by the user.
 *
 * Description: This function takes the user's input and separates it into
 * individual arguments based on spaces, new lines, and tabs. It stores these
 * arguments in an array of strings. The function supports up to MAX_ARGS - 1
 * arguments due to the NULL terminating requirement of the array.
 *
 * Return: An array of strings, where each string is one part
 * of the parsed input.
 */
char **parse_input(char *input) 
{
    int i = 0;
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;

    if (args == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return (NULL);
    }

    token = strtok(input, " \n\t");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = strdup(token); /* Duplicate token to manage memory independently */
        token = strtok(NULL, " \n\t");
    }
    args[i] = NULL; /*  NULL termination */

    return (args);
}
