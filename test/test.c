#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void display_prompt() {
    printf("simple_shell$ ");
}

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

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        display_prompt();
        read_command(command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        execute_command(command);
    }

    return 0;
}

