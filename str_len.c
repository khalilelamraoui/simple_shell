#include"shell.h"
/**
 * Get the length of a string.
 */
int string_length(char *string) {
    int index = 0;

    while (*(string + index) != '\0') {
        index++;
    }
    return index;
}
