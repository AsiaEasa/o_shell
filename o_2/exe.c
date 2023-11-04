#include "hsh.h"

/**
 * exec_arg - map if command is a builtin or a process
 * @arg: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int exec_arg(char **arg)
{int ex, re;
	struct stat stat_in;
char *_path;

	if (arg[0] == NULL)
	{
		return (-1);
	}

	if(_strncmp(arg[0], "exit", 4) == 0)
		return(own_exit(arg));

	if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
		return(env(arg));

	ex = stat(arg[0], &stat_in);
	if (ex)

	{ _path = Path(arg[0]);
		if (!_path)
		{free(_path);
			perror("./hsh");
			return(0); }
		re = create_process(arg, _path);
		free(_path);}
	else
	{_path = arg[0];
		re = create_process(arg, _path);}

	return (re);
}
