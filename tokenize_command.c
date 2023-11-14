#include "shell.h"
/**
 * tokenize_command - Tokenize the given command.
 * @command: The command to tokenize.
 * @args: The array to store the tokenized arguments.
 */
void tokenize_command(char *command, char *args[])
{
	char *token;
	int i = 0;

	while ((token = strsep(&command, " ")) != NULL)
	{
		if (*token != '\0')
		{
			args[i] = token;
			i++;
		}
	}
	args[i] = NULL;
}
