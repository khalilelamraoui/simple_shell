#include"shell.h"
/**
 * main - Entry point of the simple shell program.
 * Return: 0 on success.
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	printf("============Simple Shell============\n");
	while (display_prompt(), read_command(command),
			strcmp(command, "exit") != 0)
		execute_command(command);
	return (0);
}
