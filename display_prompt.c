#include"shell.h"
/**
 * display_prompt - Display the shell prompt
 * including the current working directory.
 */
void display_prompt(void)
{
	char cwd[MAX_BUFFER_SIZE];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s $ ", cwd);
	else
	{
		perror("getcwd");
		printf("$ ");
	}
}
