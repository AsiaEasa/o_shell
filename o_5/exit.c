#include "hsh.h"

/**
 * handle_exit - handles the 'exit' buil-in command
 * @exit_args: Arrguments for the exit command.
 * Return: Nothing
 */

int handle_exit(char **exit_args)
{ int status;
	if (exit_args[1])
	{
		if ((exit_args[1][0] == '-') ||
			(exit_args[1][0] >= 'a' && exit_args[1][0] <= 'z') ||
			(exit_args[1][0] >= 'A' && exit_args[1][0] <= 'Z'))
		{ error_exit(exit_args[1]);
			return(2); }
				else
			{ status = _atoi(exit_args[1]);
		return(status); }}
	return(0);
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
		i++;	}
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

void error_exit(char *arg_v)
{
	char *p = "Illegal number", l[BUFFER_SIZE],  m[3] = "\n";
	char *t = "exit", ptr[BUFFER_SIZE];
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
