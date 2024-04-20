#include "shell.h"

/**
 * handle_error - Handles errors by printing an error message and exiting
 *                or performing other actions based on the error code.
 * @error_message: The error message to be displayed.
 * @error_code: The error code that determines the action to be taken.
 *
 * Description: This function is called when an error occurs in the shell.
 *              It takes an error message and an error code as parameters.
 *              Depending on the error code, it may terminate the shell
 *              or perform other predefined actions. This function helps
 *              ensure that all errors are handled in a uniform manner,
 *              making the shell more robust and easier to debug.
 *              The function demonstrates how structured error handling
 *              can be implemented in a system-level application.
 *
 * Return: Nothing. If the error code indicates a critical failure,
 *         the function may terminate the program.
 */
void handle_error(const char *error_message, int error_code)
{
	fprintf(stderr, "Error (%d): %s\n", error_code, error_message);
	/* We can add more code to handle others errors  */
	if (error_code == CRITICAL_ERROR)
	{
		exit(EXIT_FAILURE);
	}
}
