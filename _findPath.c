#include "main.h"

/**
 * which_location - function that finds and generates the path for a command
 * @command: command passed form command line args
 * Return: exact path of the executable command if found, NULL if not
 */
char *which_location(char *command)
{
	char *path_ptr, *path_cpy, *token_p;
	char *created_path;
	int cmd_len, path_len;
	struct stat buff;

	path_ptr = getenv("PATH");
	if (path_ptr == NULL)
		return (NULL); /*no match found*/

	path_cpy =  _strdup(path_ptr);
	cmd_len = _strlen(command);
	token_p = strtok(path_cpy, ":");

	while (token_p != NULL)
	{
		path_len = _strlen(token_p);
		created_path = malloc(2 + path_len + cmd_len);
		_strcpy(created_path, token_p);
		_strcat(created_path, "/");/*append /, command name and null byte*/
		_strcat(created_path, command);
		_strcat(created_path, "\0");

		if (stat(created_path, &buff) == 0)
		{
			free(path_cpy);
			return (created_path); /*path to executable was found*/
		}
		free(created_path); /*search next path*/
		token_p = strtok(NULL, ":");
	}
	free(path_cpy);

	if (stat(command, &buff) == 0)
		return (command);

	return (NULL);
}
