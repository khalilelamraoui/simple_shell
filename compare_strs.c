#include"shell.h"
/**
 * compare_strings - Compare two strings.
 * @string1: The first string to be compared.
 * @string2: The second string to be compared.
 *
 * Return: 0 if the strings are equal, otherwise the difference between the
 * ASCII values of the first differing characters.
 */
int compare_strings(char *string1, char *string2)
{
	int index = 0;

	while (string1[index] && string2[index])
	{
		if (string1[index] - string2[index] != 0)
			return (string1[index] - string2[index]);
		index++;
	}
	return (0);
}
