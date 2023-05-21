#include "main.h"
/**
 * parsing_entry - Parse the given entry into an array of strings
 * based on the delimiter.
 * @entry: The entry string to parse.
 * @delim: The delimiter used to split the entry into tokens.
 * Return: An array of strings representing the tokens, or NULL on failure.
 */

char **parsing_entry(char *entry, char *delim)
{
	char *token, *entry_copy;
	size_t n_tokens;
	char **av;
	int i;

	/* copy entry */
	entry_copy = malloc(sizeof(char) * (_strlen(entry) + 1));
	if (!entry_copy)
	{
		perror("./shell");
		return (NULL);
	}
	_strcpy(entry_copy, entry);

	/* counting number of tokens in entry */
	token = _strtok(entry, delim);
	n_tokens = 0;
	while (token != NULL)
	{
		n_tokens++;
		token = _strtok(NULL, delim);
	}
	/* copy tokens into the array of strings */
	av = malloc(sizeof(char *) * (n_tokens + 1));
	if (!av)
	{
		perror("./shell");
		return (NULL);
	}
	token = _strtok(entry_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		av[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(av[i], token);

		token = _strtok(NULL, delim);
	}
	av[i] = NULL;
	free(token);
	free(entry_copy);

	is_env(av);
	is_exit(av[0], av[1]);

	return (av);
}
