#include "main.h"

/**
 * _strchr - function that locates a character in a string
 *
 * @s: ponietr to string
 * @c: character to be located
 *
 * Return: a pointer to the first occurrence of the character c in
 * the string s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{

	while (*s != '\0' && *s != c)
	{
		s++;
	}

	if (*s == c)
		return (s);
	return (NULL);
}
/**
 * _isdigit -  checks for a digit (0 through 9)
 *
 * @c: character to check
 *
 * Return: 1 if c is uppercase or 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* _strlen - returns the length of a string.
*
* @s: string.
*
* Return: length of string.
*/

int _strlen(char *s)
{
	int i;
	int length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}

/**
* _strcpy - copies the string pointed by src.
* @dest: pointer to the buffer in which the string is copied.
* @src: string to be copied.
*
* Return: the pointer to dest.
*/

char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - that concatenates two strings.
 *
 * @src: string to append
 *
 * @dest: string destination
 *
 * Return: a pointer to the resulting string dest
 *
 */
char *_strcat(char *dest, char *src)
{

	int i, j, lendest = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		lendest++;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[lendest] = src[j];

		lendest++;
	}

	dest[lendest] = '\0';
	return (dest);
}
/**
 * _strdup - duplicate string
 * @str: the string to duplicate 
 * Return: pointer points to the newly allocated memory containing
 * the duplicated string.
 */

char *_strdup(const char* str)
{
    size_t len = strlen(str) + 1;
    char* new_str = malloc(len);

    if (new_str == NULL)
    {
        return NULL;
    }

    strcpy(new_str, str);
    return new_str;
}
