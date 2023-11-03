#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * execute_command - Execute the command using fork and execvp
 * @arguments: Array containing command and arguments
 */
void execute_command(char *arguments[]);
/**
 * handle_command - Handle the input command,
 * including built-in commands
 * @input: User input command
 */
void handle_command(char *input);

#endif
