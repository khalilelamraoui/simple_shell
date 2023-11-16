#include "shell.h"
/**
 * exit_shell - Exit the shell if the command is "exit".
 * @command_tokens: The parsed command tokens.
 * @input_line: The input line.
 */
void exit_shell(char **command_tokens, char *input_line)
{
	int status;

	if (compare_strings(command_tokens[0], "exit") == 0)
	{
		if (command_tokens[1] == NULL)
		{
			free(command_tokens);
			free(input_line);
			exit(0);
		}
		else
		{
			status = atoi(command_tokens[1]);
			free(command_tokens);
			free(input_line);
			exit(status);
		}
	}
}
