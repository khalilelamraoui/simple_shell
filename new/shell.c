#include"shell.h"
/**
 * Main function for the custom shell.
 */
int main(int __attribute__((unused)) arg_count, char **arguments, char **environment) {
    size_t line_size = 0;
    char *input_line = NULL, **command_tokens, *executable_path, *prompt = "$ ";

    while (1) {
        if (isatty(STDIN_FILENO) != 0) {
            write(STDOUT_FILENO, prompt, _strlen(prompt));
        }
        input_line = NULL;
        read_line(&input_line, line_size);
        command_tokens = split(input_line, " ");
        exit_shell(command_tokens, input_line);

        executable_path = get_executable_path(command_tokens[0], environment);
        if (executable_path == NULL) {
            print_custom_error(arguments[0], command_tokens[0]);
            free(command_tokens);
            free(input_line);
            continue;
        } else {
            process_command(command_tokens, environment, executable_path, input_line);
        }
        if (isatty(STDIN_FILENO) == 0) {
            exit(0);
        }
    }
    return 0;
}
