#include "hsh.h"

/**
 * exec_arg - map if command is a builtin or a process
 * @arg: command and its flags
 *
 * Return: 1 on sucess, 0 otherwise
 */
int exec_arg(char **arg)
{
	if (arg[0] == NULL)
	{
		/* empty command was entered */
		return (-1);
	}
	/* if there is a match execute the builtin command */
	
	if(_strncmp(arg[0], "exit", 4) == 0)
		return(own_exit(arg));

	if (_strncmp(arg[0], "env", 3) == 0 || _strncmp(arg[0], "printenv", 4) == 0)
		return(env(arg));
	/* create a new process */
	return (create_process(arg));
}
