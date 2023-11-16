#include "shell.h"
/**
 * _getenv - Extracts the value of a specific environment variable.
 * @envp: The array of environment variables.
 * @var: The variable name to retrieve.
 * @length: The length of the variable name.
 * Return: A pointer to the value of the variable, or NULL if not found.
 */
char *_getenv(char **envp, char *var, unsigned int length)
{
	char *value = NULL;

	while (*envp)
	{
		if (strncmp(*envp, var, length) == 0)
		{
			value = *envp + length;
			break;
		}
		envp++;
	}
	return (value);
}
