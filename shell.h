#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10

/*  Function prototypes */
void display_prompt(void);
char **parse_input(char *input);
int execute_command(char **args);
void free_args(char **args);

#endif

