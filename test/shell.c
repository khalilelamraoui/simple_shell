#include"shell.h"
/**
 * main - Main function: Display shell prompt,
 * handle user input and execute commands
 * Return: 0 on successful completion
 */
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
