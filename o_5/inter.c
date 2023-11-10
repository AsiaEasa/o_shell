#include "hsh.h"

/**
 * interactive - UNIX command line interpreter
 *
 * Return: void
 */
void interactive(void)
{
	char *line, *prompt;
	char **arg;
	int re;

	re = -1;
	prompt = "$ ";
	while (re == -1){
		write(STDOUT_FILENO, prompt, 2);
		line = get_line();
		arg = str_tok(line);
		re = check(arg);

		free(line);
		free(arg);

		if (re >= 0)
		{
			exit(re);
		}
	}}
