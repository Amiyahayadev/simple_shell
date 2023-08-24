#include "main.h"

/**
 * exit_builtin - exits shell
 * @av: command arguments passed
 * Return: 0
 */
int exit_builtin(char **av)
{
	(void)av;

	return (0);
}

/**
 * env_builtin - prints the environment
 * @av: command arguments passed
 * Return: 1
 */

int env_builtin(char **av)
{
	unsigned int i = 0;
	ssize_t bytes_written;
	size_t len = 0;
	char *env_ptr;
	(void)av;

	while (environ[i] != NULL)
	{
		env_ptr = environ[i];
		len = _strlen(environ[i]);
		bytes_written = write(STDOUT_FILENO, env_ptr, len);
		if (bytes_written == -1)
		{
			perror("write");
			exit(1);
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}
