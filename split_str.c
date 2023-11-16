#include "shell.h"
/**
 * split_string - Split a string into tokens using a delimiter.
 * @str: The input string to be split.
 * @delim: The delimiter for splitting.
 * Return: An array of strings representing the tokens.
 */
char **split_string(char *str, char *delim)
{
	char *start, *end;
	unsigned int index = 0, num_delimiters = 0, count = 0;
	char **result;

	num_delimiters = count_delimiters(str, delim);
	result = malloc(sizeof(char *) * (num_delimiters + 2));
	index = 0;
	start = str;
	end = str;
	while (str[index])
	{
		if (str[index] == delim[0])
		{
			str[index] = '\0';
			result[count] = start;
			if (str[index + 1])
			{
				start = &str[index + 1];
				end = &str[index + 1];
				count++;
				index++;
			}
			else
			{
				start = NULL;
				break;
			}
			continue;
		}
		end++;
		index++;
	}
	if (start)
		result[count] = start;
	result[count + 1] = NULL;
	return (result);
}
