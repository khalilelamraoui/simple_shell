#include "shell.h"
/**
 * copy_n_string - Copy at most n characters from source to destination.
 * @destination: The destination buffer for the copied string.
 * @source: The source string to be copied.
 * @n: The maximum number of characters to copy.
 * Return: Pointer to the destination buffer.
 */
char *copy_n_string(char *destination, char *source, int n)
{
	int index = 0;

	while (index < n && source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	while (index < n)
	{
		destination[index] = '\0';
		index++;
	}
	return (destination);
}
