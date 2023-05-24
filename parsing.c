#include "main.h"
/**
 * parsing_entry - Parse the given entry into an array based on the delimiter.
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

	entry_copy = copy_entry_string(entry);
	if (entry_copy == NULL)
		return (NULL);
	n_tokens = count_tokens(entry, delim);
	av = allocate_token_array(n_tokens);
	if (av == NULL)
	{
		free(entry_copy);
		return (NULL);
	}
	token = tokenize_entry(entry_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		av[i] = copy_token_string(token);
		if (av[i] == NULL)
		{
			free_token_array(av, i);
			free(entry_copy);
			return (NULL);
		}
		token = tokenize_entry(NULL, delim);
	}
	av[i] = NULL;
	free(entry_copy);
	check_builtin_command(av);
	return (av);
}

/**
 * copy_entry_string - Create a copy of the entry string.
 * @entry: The entry string to copy.
 * Return: A pointer to the newly allocated copy, or NULL on failure.
 */
char *copy_entry_string(char *entry)
{
	char *copy;
	size_t len;

	if (entry == NULL)
		return (NULL);

	len = _strlen(entry) + 1;
	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
	{
		perror("./shell");
		return (NULL);
	}

	_strcpy(copy, entry);
	return (copy);
}

/**
 * count_tokens - Count the number of tokens in the entry string.
 * @entry: The entry string to count tokens in.
 * @delim: The delimiter used to split the entry.
 * Return: The number of tokens.
 */
size_t count_tokens(char *entry, char *delim)
{
	char *token;
	size_t count = 0;

	token = _strtok(entry, delim);
	while (token != NULL)
	{
		count++;
		token = _strtok(NULL, delim);
	}

	return (count);
}

/**
 * allocate_token_array - Allocate memory for the token array.
 * @n_tokens: The number of tokens in the array.
 * Return: A pointer to the allocated token array, or NULL on failure.
 */
char **allocate_token_array(size_t n_tokens)
{
	char **av;

	av = malloc(sizeof(char *) * (n_tokens + 1));
	if (av == NULL)
	{
		perror("./shell");
		return (NULL);
	}

	return (av);
}

/**
 * copy_token_string - Create a copy of the token string.
 * @token: The token string to copy.
 * Return: A pointer to the newly allocated copy, or NULL on failure.
 */
char *copy_token_string(char *token)
{
	char *copy;
	size_t len;

	if (token == NULL)
		return (NULL);

	len = _strlen(token) + 1;
	copy = malloc(sizeof(char) * len);
	if (copy == NULL)
	{
		perror("./shell");
		return (NULL);
	}

	_strcpy(copy, token);
	return (copy);
}
