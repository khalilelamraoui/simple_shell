#include"shell.h"
/**
 * Split a string into tokens using a delimiter.
 */
char **split_string(char *str, char *delim) {
    char *token;
    unsigned int count = 0;
    char **result = NULL;

    token = strtok(str, delim);
    while (token != NULL) {
        count++;
        token = strtok(NULL, delim);
    }

    result = malloc(sizeof(char *) * (count + 1));
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    strcpy(str, strtok(str, delim));
    token = strtok(NULL, delim);
    count = 0;
    while (token != NULL) {
        result[count] = strdup(token);
        if (result[count] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        count++;
        token = strtok(NULL, delim);
    }
    result[count] = NULL;
	free(result);
    return result;
}
