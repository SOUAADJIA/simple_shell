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

/**
 * int_convert_string - Convert an integer to a string.
 * @number: The integer to convert.
 *
 * Return: The string representation of the integer, or NULL if failed.
 */
char *int_convert_string(int number)
{
	int num_digits, place_value, index = 0, is_negative = 0, x;
	char *result;

	num_digits = number;
	place_value = 1;

	if (number < 0)
		is_negative = 1;

	result = malloc(sizeof(char) * (abs(num_digits) + 2 + is_negative));
	if (result == NULL)
		return (NULL);

	if (is_negative)
	{
		result[index] = '-';
		index++;
	}

	for (x = 0; num_digits > 9 || num_digits < -9; x++)
	{
		num_digits /= 10;
		place_value *= 10;
	}

	num_digits = number;
	for (; x >= 0; x--)
	{
		if (num_digits < 0)
		{
			result[index] = (num_digits / place_value) * -1 + '0';
			index++;
		}
		else
		{
			result[index] = (num_digits / place_value) + '0';
			index++;
		}
		num_digits %= place_value;
		place_value /= 10;
	}

	result[index] = '\0';

	return (result);
}