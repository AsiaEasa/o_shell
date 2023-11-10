#include "hsh.h"

/**
 * exec_arg - map if command is a builtin or a process
 * @arg: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int check(char **arg)
{
	if (arg[0] == NULL)
	{
		return (-1);
	}

	if(_strncmp(arg[0], "exit", 4) == 0)
		return(own_exit(arg));

	if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
		return(env(arg));

	if (_strncmp(arg[0], "cd", 2) == 0)
		return(cd(arg));

	return (create_process(arg));
}
