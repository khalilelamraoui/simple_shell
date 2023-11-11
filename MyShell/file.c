#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

void display_prompt() {
    printf("$ ");
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

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_index = 0;
	static ssize_t buffer_size = 0;
	size_t i = 0;

	/* Initialize the buffer*/
	if (buffer_index >= buffer_size || buffer_size == 0)
	{
        	buffer_size = read(fileno(stream), buffer, BUFFER_SIZE);
        	if (buffer_size <= 0)
		{
			/* End of file or error */
			return buffer_size;
		}
		buffer_index = 0;
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	}
	while (buffer_index < buffer_size && buffer[buffer_index] != '\n')
	{
		(*lineptr)[i++] = buffer[buffer_index++];
	}
	(*lineptr)[i] = '\0';
	if (buffer_index < buffer_size && buffer[buffer_index] == '\n')
	{
		buffer_index++;
	}
	return i;
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
