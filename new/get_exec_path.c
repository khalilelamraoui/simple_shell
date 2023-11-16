#include"shell.h"
/**
 * Get the executable path for the given command.
 */
char *get_executable_path(char *command, char **environment) {
    int index = 0;
    char *path, *env, *env_copy, **parsed_env;
    struct stat command_stat;

    if (*command == '/') {
        if (stat("/bin/ls", &command_stat) == 0) {
            return command;
        }
        return NULL;
    } else {
        env = _getenv(environment, "PATH=", 5);
        env_copy = malloc(_strlen(env) + 1);
        if (env_copy == NULL) {
            return NULL;
        }
        env_copy = _strcpy(env_copy, env);

        parsed_env = split(env_copy, ":");
        while (parsed_env[index]) {
            nconcat(3, &path, parsed_env[index], "/", command);
            if (stat(path, &command_stat) == 0) {
                free(parsed_env);
                free(env_copy);
                return path;
            }
            free(path);
            index++;
        }
    }
    free(env_copy);
    free(parsed_env);
    return NULL;
}
