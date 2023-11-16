#include "shell.h"
/**
 * print_custom_error - Print a custom error message.
 * @program_name: The name of the program.
 * @command: The command that triggered the error.
 */
void print_custom_error(char *program_name, char *command)
{
	write(STDERR_FILENO, program_name, string_length(program_name));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, command, string_length(command));
	write(STDERR_FILENO, ": not found\n", 12);
}
