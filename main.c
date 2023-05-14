#include "main.h"

/**
 * main - main function
 * @argc: length of argv
 * @argv: array of strings passed in the command-line
 * Return: Always 0 (Success) 
 */

int main(int argc, char **argv)
{
	char *prompt = "Sshell $ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t num_read;
	int action;
	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		num_read = getline(&lineptr, &n, stdin);
		if (num_read == -1)
		{
			printf("\n");
			free(lineptr);
			return (0);
		}
		lineptr[num_read - 1] = '\0'; /* remove the trailing newline character */
		action = execve(lineptr, argv, NULL);
		if (action == -1)
			printf("%s: %ld: %s: command not found\n", argv[0], num_read, lineptr); 
		free(lineptr);
		lineptr = NULL;
	}
	return (0);
}

