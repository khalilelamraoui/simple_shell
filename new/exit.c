#include"shell.h"
/**
 * Exit the shell if the command is "exit".
 */
void exit_shell(char **command_tokens, char *input_line) {
    int status;

    if (_strcmp(command_tokens[0], "exit") == 0) {
        if (command_tokens[1] == NULL) {
            free(command_tokens);
            free(input_line);
            exit(0);
        } else {
            status = atoi(command_tokens[1]);
            free(command_tokens);
            free(input_line);
            exit(status);
        }
    }
}
