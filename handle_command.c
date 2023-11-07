#include"shell.h"
/**
 * handle_command - Execute a command with arguments.
 *
 * MAX_ARGUMENTS - Function that calculates the maximum of two arguments
 *
 * This function takes command input processes it according application's.
 * This function takes two input values and returns the maximum of the two.
 */

#define MAX_ARGUMENTS 10

extern char **environ;

void handle_command(char *input)
{
	char **env = environ, *arguments[MAX_ARGUMENTS];
	char *token = strtok(input, " ");
	int arg_count = 0;

	if (strcmp(input, "exit") == 0)
	{
		printf("Exiting the shell.\n");
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(input, "env") == 0)
	{
		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else
	{
		while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
		{
			arguments[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		arguments[arg_count] = NULL;
		execute_command(arguments);
	}
}
