#include"shell.h"
/**
 * main - Main function: Display shell prompt,
 * handle user input and execute commands
 * Return: 0 on successful completion
 */
#define MAX_COMMAND_LENGTH 100
int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("Myshell ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
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
