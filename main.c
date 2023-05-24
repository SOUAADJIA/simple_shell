#include "main.h"
/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * Return: 0 on successful execution.
 */
int main(int ac, char **av)
{
	char *delim = " \t\n";
	char *entry = NULL;
	ssize_t n_read;
	size_t n = 0;
	int i;
	(void) ac;

	while (1)
	{
		print_prompt();
		n_read = read_command(&entry, &n);
		if (n_read == 1)
		{
			free(entry);
			entry = NULL;
			continue;
		}
		else
		{
			entry[n_read - 1] = '\0';
			av = parsing_entry(entry, delim);
			exec_fun(av); /* executing the first token */
			for (i = 0; av[i] != NULL; i++)
				free(av[i]);
			free(av);
		}
		free(entry);
		entry = NULL;
	}
	return (0);
}
