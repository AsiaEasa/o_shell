#include "hsh.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main(void)
{ char *line;
	char **arg;
	int stat, x;
	stat = -1;
	x = 1;

	do { if (isatty(STDIN_FILENO) == 0)
		x = 0;

		else
			_puts("$ ");
		line = get_line(); /* read line from stdin */
		arg = split(line); /* tokenize line */
		stat = exec_arg(arg);
		/* avoid memory leaks */
		free(line);
		free(arg);
		/* exit with status */
		if (stat >= 0)
		{
			exit(stat);
		}
	} while (stat == -1 && x);
	return (0);
}
