#include "shell.h"

/**
 * path_exec -  executable commands found in the env path
 * @cmd: commands  input by the user
 * Return: 0 on success or  1 on failure
 */
int path_exec(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _get_env("PATH");
	value = tokenizer(path, ":");
	while (value != NULL)
	{
		cmd_path = build_cmd(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = tokenizer(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}
