#include "hsh.h"

/**
 * create_process - create a new process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 otherwise.
 */
int my_fork(char **arg)
{
	pid_t child_ID;
	int ID_status;

	child_ID = fork();
	if (child_ID ==  0)
	{
		if (execvp(arg[0], arg) == -1)
		{ error(arg[0]);
			return(127);
		}
	}
	else if (child_ID< 0)
	perror("Error forking process");

	else
waitpid(child_ID, &ID_status, 0);

	return (-1);
}

/**
 * error - prints an error message
 * @arg_v: the argument input
 * Return: print the error message if not return 0
 */

void error(char *arg_v)
{
	char *p = "not found\n", ptr[BUFFER_SIZE];
	int in_count = 1;
	char *s = my_itoa(in_count, ptr, 10);

	write(2, "./hsh", 5);
	write(2, ": ", 2);
	write(2, s, _strlen(s));
	write(2, ": ", 2);
	write(2, arg_v, _strlen(arg_v));
	write(2, ": ", 2);
	write(2, p, _strlen(p));
}
