#include "main.h"
/**
 * tokenize_entry - Tokenize the entry string.
 * @entry: The entry string to tokenize.
 * @delim: The delimiter used to split the entry.
 * Return: A pointer to the next token found in the entry,
 * or NULL if there are no more tokens.
 */
char *tokenize_entry(char *entry, char *delim)
{
	static char *buffer;
	char *token_start;

	if (entry != NULL)
		buffer = entry;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	while (*buffer != '\0' && _strchr(delim, *buffer) != NULL)
		buffer++;

	if (*buffer == '\0')
		return (NULL);

	token_start = buffer;

	while (*buffer != '\0' && _strchr(delim, *buffer) == NULL)
		buffer++;

	if (*buffer != '\0')
	{
		*buffer = '\0';
		buffer++;
	}

	return (token_start);
}

/**
 * free_token_array - Free the memory allocated for the token array.
 * @av: The token array to free.
 * @size: The size of the token array.
 */
void free_token_array(char **av, int size)
{
	int i;

	for (i = 0; i < size; i++)
		free(av[i]);

	free(av);
}
