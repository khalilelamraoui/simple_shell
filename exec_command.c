#include "shell.h"
/**
 * execute_command - Execute the command using fork and execve.
 * @parsed_command: The parsed command and its arguments.
 * @environment: The environment variables.
 * @input_line: The input line.
 */
void execute_command(char **parsed_command,
		char **environment, char *input_line)
{
	pid_t process_id;
	int status;

	process_id = fork();
	if (process_id == 0)
	{
		execve(parsed_command[0], parsed_command, environment);
		perror(parsed_command[0]);
		if (input_line)
			free(input_line);
		free(parsed_command);
		exit(0);
	}
	else if (process_id > 0)
		wait(&status);
	else
		perror("fork");
}
