#include "shell.h"
/**
 * string_length - Get the length of a string.
 * @string: The input string.
 * Return: The length of the string.
 */
int string_length(char *string)
{
	int index = 0;

	while (*(string + index) != '\0')
		index++;
	return (index);
}
