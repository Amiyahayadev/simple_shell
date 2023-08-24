#include "main.h"

/**
 * execute_cmd - Handles built-in commands or execute external commands
 * @av: array of command arguments to be executed
 * @env: our shells environment vairables
 * @prog_name: the shell name
 * Return: 0 on success, -1 on failure
 */
int execute_cmd(char **av, char **env, char *prog_name)
{
	int status;

	if (av == NULL)
		return (-1);

	status = exec_builtins(av);
	if (status != -1)
		return (status); /*found a builtin*/

	return (exec_external(av, env, prog_name));
}
/**
 * exec_builtins - Searchs for appropriate built-in function and calls it
 * @av: array of comwmand arguments to be executed
 * Return: 1 on success, -1 on failure
 */
int exec_builtins(char **av)
{
	int i;

	func_builtin builtIns[] = {
		exit_builtin,
		env_builtin
	};
	char *builtin_cmds[] = {
		"exit",
		"env",
		NULL
	};

	for (i = 0; builtin_cmds[i] != NULL; i++)
		if (_strcmp(av[0], builtin_cmds[i]) == 0)
			return (builtIns[i](av));
	return (-1);
}
/**
 * exec_external - creates process to execute a non-built-in command
 * @av: array of command arguments to be executed
 * @env: environment vaariable
 * @prog_name: the name of our shell
 * Return: 1 on success, exit on failure
 */
int exec_external(char **av, char **env, char *prog_name)
{
	int status;
	char *exact_path;
	pid_t pid;

	exact_path = which_location(av[0]); /*generate path*/

	if (exact_path)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(prog_name);
			return (-1);
		}
		if (pid == 0)
		{
			if (execve(exact_path, av, env) == -1)
			{
				perror(prog_name);
				exit(2);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror(prog_name);
				exit(1);
			}
		}
	}
	else
	{
		perror(prog_name);
		return (-1);
	}
	return (1);
}
