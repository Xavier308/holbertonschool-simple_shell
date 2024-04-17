#include "shell.h"

/**
 * display_prompt - Displays the shell prompt "#supershell$ ".
 *
 * Description: This function prints the custom prompt for the shell, which is
 * "#supershell$ ". It ensures the prompt is displayed immediately by flushing
 * the standard output buffer.
 */
void display_prompt(void)
{
	printf("#supershell$ "); /* Print the prompt text */

	/* Flush the output buffer to ensure prompt shows immediately */
	fflush(stdout);
}
