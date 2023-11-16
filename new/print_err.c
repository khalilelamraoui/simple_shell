#include"shell.h"
/**
 * Print a custom error message.
 */
void print_custom_error(char *program_name, char *command) {
    write(STDERR_FILENO, program_name, _strlen(program_name));
    write(STDERR_FILENO, ": 1: ", 5);
    write(STDERR_FILENO, command, _strlen(command));
    write(STDERR_FILENO, ": not found\n", 12);
}
