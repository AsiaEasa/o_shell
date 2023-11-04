#include "hsh.h"

/**
 * split - split a string into multiple strings
 * @line: string to be splited
 *
 * Return: pointer that points to the new array
 */
char **split(char *line)
{
	int buffersize, j, i;
	char **given_tokens;
	char *token, *t, str[BUFFER_SIZE];

	buffersize = 1024;
	j = 0;
	i = 0;
	given_tokens = malloc(buffersize * sizeof(char *));

	if (!given_tokens)
	{
		_puts("allocation error in split_line: tokensi\n");
		exit(EXIT_FAILURE);
	}
	_strcpy(str,line);
	token = str;
	t = str;
	while (str[j] != '\0')
	{if (str[j] == ' ')
		{
			str[j] = '\0';
			given_tokens[i++] = token;
			t++;
			token = t;
			t = &str[j];
		}
		if (token[0] == '#')
		{ 
		given_tokens[i] = NULL;
		return (given_tokens);
		}
		t++;
		j++;
	}
	given_tokens[i++] = token;
	given_tokens[i] = NULL;
	return (given_tokens);
}
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
