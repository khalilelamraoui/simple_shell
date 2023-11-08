#include"shell.h"
/**
 * Executes the provided command.
 * @param command The command to be executed.
 */
void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    int i = 0;
    pid_t pid;

    /* Tokenizing the command */
    char *token = strtok(command, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    /* Execute the command */
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        /* Child process */
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */
        wait(NULL);
    }
}
