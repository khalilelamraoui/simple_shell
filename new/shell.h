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

/* Custom getline function */
ssize_t custom_getline(char **input, size_t *size, FILE *stream);
/* Command execution */
void execute_command(char **parsed_command, char **environment, char *input_line);
/* Get executable path for a command */
char *get_executable_path(char *command, char **environment);
/* Exit the shell */
void exit_shell(char **command_tokens, char *input_line);
/* Read a line of input */
void read_line(char **input_line, size_t size);
/* Main function for the custom shell */
int main(int argc, char **argv, char **environment);
/* Print custom error message */
void print_custom_error(char *program_name, char *command);
/* Free memory allocated for multiple pointers */
void free_memory(int count, char *allocation1, ...);
/* Handle the command */
void handle_command(char **tokens, char **environment, char *cmd_exec, char *line);
/* Split a string into tokens using a delimiter */
char **split_string(char *str, char *delim);
/* Copy a string from source to destination */
char *copy_string(char *destination, char *source);
/* Copy at most n characters from source to destination */
char *copy_n_string(char *destination, char *source, int n);
/* Compare two strings */
int compare_strings(char *string1, char *string2);
/* Get the length of a string */
int string_length(char *string);
/* Concatenate multiple strings */
ssize_t concatenate_strings(int count, char **result, ...);
/* Other functions */
int get_num_delim(char *str, char *delim);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
ssize_t nconcat(int n, char **strcat, ...);
void print_error(char *argv, char *cmd);
void free_alloc(int n, char *alloc1, ...);
void handle_cmd(char **tokens, char **envp, char *cmd_exec, char *line);
char *_getenv(char **envp, char *var, unsigned int n)

#endif
