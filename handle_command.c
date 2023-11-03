#include"shell.h"
/**
 * handle_command - Handle the input command, including built-in commands
 * @input: User input command
 */
#define MAX_ARGUMENTS 10
void handle_command(char *input)
{
	extern char **environ;
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
