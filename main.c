#include "main.h"
/**
 * main - Entry point of the program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the command-line arguments.
 * Return: 0 on successful execution.
 */
int main(__attribute__((unused)) int ac, char **av)
{
	char *delim = " \t\n";
	char *entry = NULL;
	ssize_t n_read;
	size_t n = 0;
	int i;
	int interactive = isatty(STDIN_FILENO); /*Check if in inter mode*/

	while (1)
	{
		print_prompt(interactive);
		n_read = read_command(&entry, &n, interactive);
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
			exec_fun(av);
			for (i = 0; av[i] != NULL; i++)
				free(av[i]);
			free(av);
		}
		free(entry);
		entry = NULL;
	}
	return (0);
}
