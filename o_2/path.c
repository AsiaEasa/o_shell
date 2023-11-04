#include "hsh.h"

/**
 * Path - checks if a file exists in PATH
 * @command: command input
 * Return: The full path of the file or NULL if not found.
 */
char *Path(char *command)
{
	char *path = in_env("PATH");
	char *pathCopy = _strdup(path);
	char *token = pathCopy;
	char *fullPath = NULL;

	while (token != NULL && *token != '\0')
	{ char *delimiter = _strchr(token, ':');
		if (delimiter != NULL)

			*delimiter = '\0';

		fullPath = str_concat(token, "/", command);
		if (fullPath != NULL)
		{
			if (access(fullPath, X_OK) == 0)
			{ free(pathCopy);
				return (fullPath); }

			free(fullPath);
			token = delimiter != NULL ? delimiter + 1 : NULL;
		} else
		{perror("memory");
			free(fullPath);
			exit(EXIT_FAILURE); }
	}
	return (NULL); }
/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
/**
 *_strcat - concatenates two string
 * @dest: input value
 * @src: input value
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
