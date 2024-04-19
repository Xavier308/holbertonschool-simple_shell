#include "shell.h"

/**
 * display_prompt - Displays the shell prompt "#supershell$ ".
 *
 * Description: This function prints the custom prompt for the shell, which is
 * "#supershell$ ". It ensures the prompt is displayed immediately by flushing
 * the standard output buffer.
 * The prompt is not displayed if the input is not
 * from a terminal (i.e., in non-interactive mode).
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO)) /*  Check if the stdin is a terminal */
	{
		printf("#supershell$ "); /* Print the prompt text */
		/* Flush the output buffer to ensure prompt shows immediately */
		fflush(stdout);
	}
}
