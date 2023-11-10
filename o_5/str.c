#include "hsh.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strncmp - This program compares the first n characters of two strings.
 *@str1:First string to be competed.
 *@str2: Second string to be competed.
 * @n: Number of characters to compare.
 *Return: negative, positive or zero integer.
 */

int _strncmp(char *str1, char *str2, int n)
{ int i, diff;

	for (i = 0; i < n; i++)
	{
		diff = str1[i] - str2[i];
		if (diff > 0 || diff < 0)
			return (diff); }
	return (0);
}
/**
 * _puts - function that prints a string to stdout
 *
 * @str: char pointer variable
 *
 * Return: nothing
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
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
