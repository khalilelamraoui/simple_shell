#include"shell.h"
/**
 * Reads the command entered by the user.
 * @param command The command entered by the user.
 */
void read_command(char *command) {
    size_t length;
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    /* Remove newline character */
    length = strlen(command);
    if (command[length - 1] == '\n') {
        command[length - 1] = '\0';
    }
}
