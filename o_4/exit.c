#include "hsh.h"

/**
 * own_exit - causes normal process termination
 * @args: empty args
 *
 * Return: 0 to terminate the process
 */
int own_exit(char **exit_args)
{
	int status =  EXIT_SUCCESS;

	if (exit_args[1])
	{ if (exit_args[1][0] == '-')
		{error_exit(exit_args[1]);
			free(exit_args);
			exit(2); }
		else if (exit_args[1][0] >= 'a' && exit_args[1][0] <= 'z')
		{ error_exit(exit_args[1]);
			free(exit_args);
			exit(2); }
		else if (exit_args[1][0] >= 'A' && exit_args[1][0] <= 'Z')
		{ error_exit(exit_args[1]);
			free(exit_args);
			exit(2); }
		else
		{ status = _atoi(exit_args[1]);
			free(exit_args);
			exit(status); }}

	free(exit_args);
	exit(0);
}
/**
 * _atoi - convert a string into an integer.
 * @s: the string to use.
 * Return: integer.
 */

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

/**
 * error_exit - prints an error message
 * @arg_v: the argument input
 * Return: print the error message if not return 0
 */

void error_exit(char *arg_v) {
	char *p = "Illegal number", l[BUFFER_SIZE],  m[3] = "\n", *t = "exit", ptr[BUFFER_SIZE];
	int in_count = 1;
	char *s = my_itoa(in_count, ptr, 10);
	strcpy(l, arg_v);
	strcat(l, m);
	arg_v = l;
	write(2, "./hsh", 5);
	write(2, ": ", 2);
	write(2, s, _strlen(s));
	write(2, ": ", 2);
	write(2, t, _strlen(t));
	write(2, ": ", 2);
	write(2, p, _strlen(p));
	write(2, ": ", 2);
	write(2, arg_v, _strlen(arg_v));

}
/**
 * reverse - Reverses the characters in a character array.
 * @str: The character array to be reversed.
 * @length: The length of the character array.
 */

void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
 * my_itoa - Convert an integer to a string
 * @num: The integer to be converted.
 * @str: Character array to store the resulting string.
 * @base: The base for the conversion .
 * Return: A pointer to the 'str' array,
 * which contains the string representation
 * of the input 'num' in the specified 'base'.
 */

char *my_itoa(int num, char str[], int base)
{
	int i = 0;

	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}

	str[i] = '\0';
	reverse(str, i);

	return (str);
}
