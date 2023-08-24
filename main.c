#include "main.h"

/**
 * main - Program entry
 * @argv: command line arguments
 * @argc: no of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char **env = environ;
	char **arg = NULL;
	unsigned int i = 1;
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		hsh_loop(env, argv[0]);
	}
	else
	{
		arg = &argv[i];
		execute_cmd(arg, env, argv[0]);
	}

	return (0);
}
