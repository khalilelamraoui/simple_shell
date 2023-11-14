#include"shell.h"
/**
 * read_command - Read a command from standard input.
 * @command: Buffer to store the read command.
 */
void read_command(char *command)
{
	size_t length;

	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	length = strlen(command);
	if (command[length - 1] == '\n')
		command[length - 1] = '\0';
}
