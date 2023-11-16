#include "shell.h"
/**
 * count_delimiters - Count the occurrences of a delimiter in a string.
 * @str: The input string.
 * @delim: The delimiter to count.
 * Return: The number of occurrences of the delimiter.
 */
int count_delimiters(char *str, char *delim)
{
	int i = 0, num_delimiters = 0;

	while (str[i])
	{
		if (str[i] == delim[0])
			num_delimiters++;
		i++;
	}
	return (num_delimiters);
}
