#include "shell.h"
/**
 * process_command - Process a command.
 * @command_tokens: The tokens of the command.
 * @environment: The array of environment variables.
 * @executable_path: The executable path for the command.
 * @input_line: The input line.
 */
void process_command(char **command_tokens, char **environment,
		char *executable_path, char *input_line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		execve(executable_path, command_tokens, environment);
		perror(command_tokens[0]);
		if (input_line)
			free(input_line);
		free(command_tokens);
		exit(0);
	}
	else if (pid > 0)
		wait(&status);
	else
		perror("fork");
}
