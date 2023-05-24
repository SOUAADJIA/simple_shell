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
	int interactive = isatty(STDIN_FILENO); /* Check if in interactive mode */

	while (1)
	{
		print_prompt(interactive);
		n_read = read_command(&entry, &n, interactive);
		if (n_read <= 0)
		{
			if (n_read == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			continue;
		}
		entry[n_read - 1] = '\0';
		if (is_empty_input(entry))
		{
			free(entry);
			entry = NULL;
			continue;
		}
		av = parsing_entry(entry, delim);
		exec_fun(av);
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
		free(entry);
		entry = NULL;
	}
	return (0);
}

/**
 * is_empty_input - Check if the input string is empty (only spaces or tabs)
 *
 * @entry: The input string to check.
 *
 * Return: 1 if the input is empty, 0 otherwise.
 */
int is_empty_input(char *entry)
{
	while (*entry != '\0')
	{
		if (*entry != ' ' && *entry != '\t')
		{
			return (0);  /* Not empty input*/
		}
		entry++;
	}
	return (1);  /* Empty input*/
}

