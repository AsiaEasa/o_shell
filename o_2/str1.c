#include "hsh.h"
/**
 *_strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */
char *_strdup(char *str)
{
	char *aaa;
	int i, r = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	aaa = malloc(sizeof(char) * (i + 1));

	if (aaa == NULL)
		return (NULL);

	for (r = 0; str[r]; r++)
		aaa[r] = str[r];
	return (aaa);
}
/**
 * str_concat - concatenates three strings
 * @word1: input value
 * @word2: input value
 * @word3: input value
 * Return: void
 */

char *str_concat(char *word1, char *word2, char *word3)
{
	int total_length = _strlen(word1) + _strlen(word2) + _strlen(word3) + 1;
	char *result = malloc(total_length * sizeof(char));

	if (result == NULL)
	{
		return (NULL); }
	_strcpy(result, word1);
	_strcat(result, word2);
	_strcat(result, word3);
	return (result); }
/**
 *in_env - gets the value of a speficied environment variable
 * @in_env: Variable to look for in environment
 * Return: Pointer to start index of the value.
 */

char *in_env(char *in_env)
{
	char **ptr = environ;
	int len = _strlen(in_env);

	while (*ptr)
	{

		if (_strncmp(*ptr, in_env, len) == 0 && (*ptr)[len] == '=')
		{
			return (&((*ptr)[len + 1]));
		}
		ptr++;
	}
	return (NULL);
}
