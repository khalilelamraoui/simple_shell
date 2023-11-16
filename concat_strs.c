#include "shell.h"
/**
 * concatenate_strings - Concatenate multiple strings.
 * @count: The number of strings to concatenate.
 * @result: Pointer to the resulting concatenated string.
 * @...: Variable number of strings to concatenate.
 * Return: 0 on success, -1 on failure.
 */
ssize_t concatenate_strings(int count, char **result, ...)
{
	va_list arguments;
	char *string;
	int i, j = 0, length = 0, copy_at = 0;

	va_start(arguments, result);
	for (i = 0; i < count; i++)
		length += string_length(va_arg(arguments, char *));
	va_start(arguments, result);
	*result = malloc(sizeof(char) * (length + 1));
	if (*result == NULL)
		return (-1);
	for (i = 0; i < count; i++)
	{
		string = va_arg(arguments, char *);
		if (string == NULL)
			continue;
		while (string[j])
		{
			(*result)[copy_at] = string[j];
			copy_at++;
			j++;
		}
		j = 0;
	}
	(*result)[length] = '\0';
	return (0);
}
