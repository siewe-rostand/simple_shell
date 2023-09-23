#include "shell.h"

/**
 * show_env - function to show enviroment variable
 * @cmd: parsed command
 * @st: latest cmd status
 * Return: Always 0
 */
int show_env(__attribute__((unused)) char **cmd,
		__attribute__((unused)) int st)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
 * _cd - Changes directory
 * @cmd: cmd to be parse
 * @st: latest cmd status
 * Return: 0 on success 1 on error (For OLDPWD Always 0 incase of no OLDPWD)
 */
int _cd(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("shell");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
