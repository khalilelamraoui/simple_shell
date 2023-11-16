#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

ssize_t custom_getline(char **input, size_t *size, FILE *stream);
void execute_command(char **parsed_command,
		char **environment, char *input_line);
char *get_executable_path(char *command, char **environment);
void exit_shell(char **command_tokens, char *input_line);
void read_line(char **input_line, size_t size);
int main(int argc, char **argv, char **environment);
void print_custom_error(char *program_name, char *command);
void free_memory(int count, char *allocation1, ...);
void handle_command(char **tokens, char **environment,
		char *cmd_exec, char *line);
char **split_string(char *str, char *delim);
char *copy_string(char *destination, char *source);
char *copy_n_string(char *destination, char *source, int n);
int compare_strings(char *string1, char *string2);
int string_length(char *string);
ssize_t concatenate_strings(int count, char **result, ...);
int count_delimiters(char *str, char *delim);
void process_command(char **command_tokens, char **environment,
		char *executable_path, char *input_line);
/* Other functions */
int get_num_delim(char *str, char *delim);
void print_error(char *argv, char *cmd);
void free_alloc(int n, char *alloc1, ...);
void handle_cmd(char **tokens, char **envp, char *cmd_exec, char *line);
char *_getenv(char **envp, char *var, unsigned int length);
#endif
