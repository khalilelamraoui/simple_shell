#include"shell.h"
/**
 * change_directory - Change the current working directory
 * based on the given directory.
 * @directory: The target directory.
 */
void change_directory(char *directory)
{
	char cwd[MAX_BUFFER_SIZE];

	if (directory == NULL || strcmp(directory, "~") == 0)
		chdir(getenv("HOME"));
	else if (strcmp(directory, "-") == 0)
	{
		char *prevDir = getenv("OLDPWD");

		if (prevDir != NULL)
			chdir(prevDir);
		else
			fprintf(stderr, "cd: OLDPWD not set\n");
	}
	else
	{
		if (chdir(directory) != 0)
			perror("cd");
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	else
		perror("getcwd");
}
