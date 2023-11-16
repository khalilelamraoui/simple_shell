#include "shell.h"
/**
 * handle_command - Handle the command by determining
 * whether it's an absolute path or using PATH.
 * @tokens: The parsed command tokens.
 * @environment: The array of environment variables.
 * @cmd_exec: The executable command path.
 * @line: The input line.
 */
void handle_command(char **tokens, char **environment,
		char *cmd_exec, char *line)
{
	if (*tokens[0] == '/')
	{
		execute_command(tokens, environment, line);
		free(tokens);
		free(line);
	}
	else
	{
		tokens[0] = realloc(tokens[0], string_length(cmd_exec) + 1);
		if (tokens[0] == NULL)
			perror("realloc");
		tokens[0] = copy_string(tokens[0], cmd_exec);
		execute_command(tokens, environment, line);
		free(tokens[0]);
		free(tokens);
		free(cmd_exec);
	}
}
