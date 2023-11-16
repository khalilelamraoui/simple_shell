#include "shell.h"
/**
 * read_line - Read a line of input.
 * @input_line: Pointer to the input buffer.
 * @size: Size of the input buffer.
 */
void read_line(char **input_line, size_t size)
{
	if (custom_getline(input_line, &size, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
}
