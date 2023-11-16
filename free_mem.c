#include "shell.h"
/**
 * free_memory - Free memory allocated for multiple pointers.
 * @count: The number of pointers to free.
 * @allocation1: The first pointer to free.
 * @...: Additional pointers to free.
 */
void free_memory(int count, char *allocation1, ...)
{
	va_list args;
	int i;

	va_start(args, allocation1);
	for (i = 0; i < count; i++)
		free(va_arg(args, char *));
	va_end(args);
}
