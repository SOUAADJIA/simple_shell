#include "main.h"
/**
 * _strncmp - compare n bytes 
 * @str1: Pointer to the first string
 * @str2: Pointer to the second string
 * @n: Maximum number of characters to compare
 *
 * Return: An integer less than, equal to, or greater than zero if str1 is
 * found, respectively, to be less than, to match, or be greater than str2.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++) 
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
 * _strchr - Locate the first occurrence of a character in a string.
 *
 * @s: The string to search in.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 * or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }

    if (*s == c)
        return ((char *)s);

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
/**
 * _strcmp - compare string values
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * _atoi - Convert a string to an integer.
 *
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int c = 0;
	unsigned int i = 0;
	int min = 1;
	int j = 0;

	while (s[c])
	{
		if (s[c] == '-')
		{
			min *= -1;
		}

		while (s[c] >= '0' && s[c] <= '9')
		{
			j = 1;
			i = (i * 10) + (s[c] - '0');
			c++;
		}

		if (j == 1)
		{
			break;
		}
		c++;
	}

	i *= min;
	return (i);
}
