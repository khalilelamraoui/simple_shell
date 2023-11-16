#include "shell.h"

/**
 * Get the value of an environment variable.
 *
 * @param envp: The array of environment variables.
 * @param var: The variable to search for.
 * @param n: The length of the variable name.
 * @return: A pointer to the value of the variable, or NULL if not found.
 */
char *_getenv(char **envp, char *var, unsigned int n) {
    while (*envp) {
        if (strncmp(*envp, var, n) == 0) {
            return *envp + n;
        }
        envp++;
    }
    return NULL;
}
