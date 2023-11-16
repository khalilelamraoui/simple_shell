#include "shell.h"
/**
 * copy_string - Copy a string from source to destination.
 * @destination: The destination buffer for the copied string.
 * @source: The source string to be copied.
 * Return: Pointer to the destination buffer.
 */
char *copy_string(char *destination, char *source)
{
	int index = 0;

	while (*(source + index) != '\0')
	{
		*(destination + index) = *(source + index);
		index++;
	}
	*(destination + index) = '\0';
	return (destination);
}
