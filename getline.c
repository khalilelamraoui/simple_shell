#include "shell.h"
/**
 * custom_getline - Custom getline function to read input from stream.
 * @input: Pointer to the input buffer.
 * @size: Pointer to the size of the input buffer.
 * @stream: The input stream.
 * Return: The number of characters read, -1 on failure.
 */
ssize_t custom_getline(char **input, size_t *size, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	ssize_t read_size;

	read_size = read(fileno(stream), buffer, BUFFER_SIZE);
	if (read_size <= 0)
		return (-1);
	else if (buffer[read_size - 1] == '\n')
	{
		*size = read_size;
		*input = realloc(*input, sizeof(char) * read_size);
		if (*input == NULL)
			return (-1);
		copy_n_string(*input, buffer, read_size);
		(*input)[read_size - 1] = '\0';
		return (read_size - 1);
	}
	else
	{
		while (read_size != -1)
		{
			*size += read_size;
			*input = realloc(*input, sizeof(char) * (*size));
			if (*input == NULL)
				return (-1);
			*input = copy_n_string(*input + (*size - read_size), buffer, read_size);
			if (buffer[read_size - 1] == '\n')
				break;
			read_size = read(fileno(stream), buffer, BUFFER_SIZE);
		}
	}
	return (*size - 1);
}
