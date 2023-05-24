#include "main.h"

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
