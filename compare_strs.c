#include"shell.h"
/**
 * Compare two strings.
 */
int compare_strings(char *string1, char *string2)
{
    int index = 0;

    while (string1[index] && string2[index]) {
        if (string1[index] - string2[index] != 0)
            return string1[index] - string2[index];
        index++;
    }
    return (0);
}