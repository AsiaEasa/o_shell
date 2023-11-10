#include "hsh.h"

/**
 * none_interactive - unix command line interpreter
 *
 * Return: void
 */
void none_interactive(void)
{
	char *line;
	char **arg;

	int re = -1;

	while (re == -1)
	{
		line = _read();
		arg = str_tok(line);
		re = check(arg);
		
		free(line);
		free(arg);
		
		if (re >= 0)
		{
			exit(re);
		}
	}}
