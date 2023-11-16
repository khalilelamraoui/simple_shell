#include"shell.h"
/**
 * Copy a string from source to destination.
 */
char *copy_string(char *destination, char *source) {
    int index = 0;

    while (*(source + index) != '\0') {
        *(destination + index) = *(source + index);
        index++;
    }
    *(destination + index) = '\0';
	free(destination);
    return destination;
}
