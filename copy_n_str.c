#include"shell.h"
/**
 * Copy at most n characters from source to destination.
 */
char *copy_n_string(char *destination, char *source, int n) {
    int index = 0;

    while (index < n && source[index] != '\0') {
        destination[index] = source[index];
        index++;
    }
    while (index < n) {
        destination[index] = '\0';
        index++;
    }
    return destination;
}
