#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt
 * including the current working directory.
 */
void display_prompt(void);
/**
 * custom_getline - Custom implementation of reading a line
 * from standard input.
 * Return: Pointer to the allocated memory containing the input line.
 */
char *custom_getline();
/**
 * change_directory - Change the current working directory
 * based on the given directory.
 * @directory: The target directory.
 */
void change_directory(char *directory);
/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
 */
void execute_command(char *command);
/**
 * read_command - Read a command from standard input.
 * @command: Buffer to store the read command.
 */
void read_command(char *command);
/**
 * tokenize_command - Tokenize the given command.
 * @command: The command to tokenize.
 * @args: The array to store the tokenized arguments.
 */
void tokenize_command(char *command, char *args[]);

#endif
