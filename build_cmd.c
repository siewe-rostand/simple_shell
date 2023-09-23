#include "shell.h"

/**
 * build_cmd - function to build cmd
 * @token: command to be executed
 * @dir: directory of the command
 * Return: full command path or null on error
 */

char *build_cmd(char *token, char *dir)
{
	char *cmd;
	size_t len;

	len = _strlen(dir) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, dir);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}
