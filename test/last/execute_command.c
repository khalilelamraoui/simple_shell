#include"shell.h"
/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	pid_t pid;

	if (strncmp(command, "cd", 2) == 0)
	{
		tokenize_command(command, args);
		change_directory(args[1]);
	}
	else
	{
		tokenize_command(command, args);
		pid = fork();
		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(NULL);
	}
}
