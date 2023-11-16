#include "shell.h"
/**
 * get_executable_path - Get the full path of an executable command.
 * @command: The command to find.
 * @environment: The array of environment variables.
 * Return: A pointer to the full path of the command, or NULL if not found.
 */
char *get_executable_path(char *command, char **environment)
{
	int i = 0;
	char *path, *env, *env_copy, **parsed_env;
	struct stat cstat;

	if (*command == '/')
	{
		if (stat("/bin/ls", &cstat) == 0)
			return (command);
		return (NULL);
	}
	else
	{
		env = _getenv(environment, "PATH=", 5);
		env_copy = malloc(string_length(env) + 1);
		if (env_copy == NULL)
		return (NULL);
		env_copy = copy_string(env_copy, env);
		parsed_env = split_string(env_copy, ":");
		while (parsed_env[i])
		{
			concatenate_strings(3, &path, parsed_env[i], "/", command);
			if (stat(path, &cstat) == 0)
			{
				free(parsed_env);
				free(env_copy);
				return (path);
			}
			free(path);
			i++;
		}
	}
	free(env_copy);
	free(parsed_env);
	return (NULL);
}
