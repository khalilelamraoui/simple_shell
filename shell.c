#include"shell.h"
/**
 * main - Main function: Display shell prompt,
 * handle user input and execute commands
 * Return: 0 on successful completion
 */
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
int main() {
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ "); // Display the prompt
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n"); // Handle Ctrl+D (EOF)
				break;
			}
		}
		input[strcspn(input, "\n")] = 0;
		if (strlen(input) == 0)
			continue;
		handle_command(input);
	}
	return (0);
}
