#include"shell.h"
/**
 * Print a custom error message.
 */
void print_custom_error(char *program_name, char *command) {
    write(STDERR_FILENO, program_name, string_length(program_name));
    write(STDERR_FILENO, ": 1: ", 5);
    write(STDERR_FILENO, command, string_length(command));
    write(STDERR_FILENO, ": not found\n", 12);
}
