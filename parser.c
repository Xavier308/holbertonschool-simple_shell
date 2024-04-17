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
	/* Allocate memory for arguments */
	char **args = malloc(MAX_ARGS * sizeof(char *));
	int i = 0; /* Index for filling the args array */

	args[i] = strtok(input, " \n\t"); /* Initialize the parsing */

	/* Parsing until no more or limits is reached  */
	while (args[i] != NULL && i < MAX_ARGS - 1)

		/* Parse the next token using the same delimiters */
		args[++i] = strtok(NULL, " \n\t");

	return (args);
}

