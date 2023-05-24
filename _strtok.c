#include "main.h"
/**
 * _strtok - Breaks a string into a sequence of tokens based on delimiters.
 * @str: The string to tokenize.
 * @delim: The delimiter string used to determine token boundaries.
 * Return: A pointer to the next token found in `str`, or NULL if there are no
 */

char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token_start;

	if (str != NULL)
		buffer = str;

	if (buffer == NULL || *buffer == '\0')
		return (NULL);

	/* Skip leading delimiters */
	while (*buffer != '\0' && _strchr(delim, *buffer) != NULL)
		buffer++;

	if (*buffer == '\0')
		return (NULL);

	token_start = buffer;

	/* Find the end of the token */
	while (*buffer != '\0' && _strchr(delim, *buffer) == NULL)
		buffer++;

	if (*buffer != '\0')
	{
		*buffer = '\0'; /* Replace the delimiter with null character */
		buffer++;
	}

	return (token_start);
}
