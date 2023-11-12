#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void display_prompt() {
    printf("$ ");
}

char *custom_getline() {
    static char buffer[MAX_BUFFER_SIZE];
    static int buffer_index = 0;
    static int buffer_size = 0;

    char *line = NULL;
    int line_index = 0;

    while (buffer_index < buffer_size || (buffer_size = read(STDIN_FILENO, buffer, MAX_BUFFER_SIZE)) > 0) {
        while (buffer_index < buffer_size) {
            char current_char = buffer[buffer_index++];
            if (current_char == '\n' || current_char == '\0') {
                line = realloc(line, line_index + 1);
                line[line_index] = '\0';
                return line;
            }
            line = realloc(line, line_index + 1);
            line[line_index++] = current_char;
        }
    }

    return line;
}

void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    int i = 0;
    pid_t pid;

    char *token = strtok(command, " ");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
    }
}

void read_command(char *command) {
    size_t length;
    if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
        printf("\n");
        exit(EXIT_SUCCESS);
    }
    length = strlen(command);
    if (command[length - 1] == '\n') {
        command[length - 1] = '\0';
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (display_prompt(), read_command(command), strcmp(command, "exit") != 0) {
        execute_command(command);
    }

    return 0;
}
