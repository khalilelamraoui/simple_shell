#include"shell.h"
/**
 * execute_command - Execute the command using fork and execvp
 * @arguments: Array containing command and arguments
 */
void execute_command(char *arguments[])
{
	pid_t child_pid;
	int status;

	if (access(arguments[0], X_OK) != -1)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror("fork");
		else if (child_pid == 0) {
			if (execvp(arguments[0], arguments) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
			waitpid(child_pid, &status, 0);
	}
	else
		printf("Command not found or not executable: %s\n",
				arguments[0]);
}
