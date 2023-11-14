#include "shell.h"
/**
 * tokenize_command - Tokenize the given command.
 * @command: The command to tokenize.
 * @args: The array to store the tokenized arguments.
 */
void tokenize_command(char *command, char *args[])
{
	char *token = strtok(command, " ");
	int i = 0;

	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
}
