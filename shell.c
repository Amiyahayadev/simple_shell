#include "main.h"

/**
 * hsh_loop - shell loop that displays input prompt, reads line,
 * parses and executes commands
 * @env: shell evnironment variables
 * @prog_name: name of shell program
 * Return: nothing
 */
void hsh_loop(char **env, char *prog_name)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1;

	while (status)
	{
		write(STDIN_FILENO, "$ ", 2);

		line = hsh_read_line();
		if (line == NULL)
			continue;

		args = parse_line(line);
		status = execute_cmd(args, env, prog_name);

		if (line != NULL)
			free(line);
		free_tokens(args);
	}
}

/**
 * hsh_read_line - function that reads a line and prints it
 *
 * Return: line read from stream or -1 on ERROR
 */
char *hsh_read_line(void)
{
	ssize_t ret;
	char *line_buff = NULL;
	size_t bufsize = 0;

	ret = getline(&line_buff, &bufsize, stdin);
	if (ret == -1)
	{
		if (ret == EOF)
		{
			free(line_buff);
			exit(0);
		}
		else
		{
			perror("Readline");
			exit(1);
		}
	}
	return (line_buff);
}

/**
 * parse_line - splits the user input into an array of strings
 * @line: address of buffer that holds line string
 * Return: tokenized strings
 */
char **parse_line(char *line)
{
	size_t i = 0, k = 0, num_tokens = 0;
	const char *delim = " \n\t";
	char **token_string = NULL;
	char *line_cp = NULL, *token_ptr = NULL;

	line_cp = _strdup(line);
	token_ptr = strtok(line_cp, delim);
	while (token_ptr != NULL)
	{
		num_tokens++;
		token_ptr = strtok(NULL, delim);
	}
	free(line_cp);

	if (num_tokens != 0)
	{
		token_string = malloc((num_tokens + 1) * sizeof(char *));
		if (token_string == NULL)
		{
			perror("malloc");
			exit(1);
		}
		token_ptr = strtok(line, delim);
		while (token_ptr != NULL)
		{
			token_string[i] = _strdup(token_ptr);
			if (token_string[i] == NULL)
			{
				while (k < i)
					free(token_string[k]), k++;

				free(token_string);
				return (NULL);
			}
			i++;
			token_ptr = strtok(NULL, delim);
		}
		token_string[i] = NULL;
	}
	return (token_string);
}

/**
 * free_tokens - free all blocks of tokenized strings
 * @token_string: pointer to array of token pointers
 * Return: void
 */
void free_tokens(char **token_string)
{
	size_t i;

	if (token_string == NULL)
		return;

	for (i = 0; token_string[i] != NULL; i++)
	{
		free(token_string[i]);
	}
	free(token_string);
}
