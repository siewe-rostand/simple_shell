#include "shell.h"

/**
 * check_path - check if input contain path
 * @input: input to be check
 * Return: 0 if success else -1
 */

int check_path(char *input)
{
	if (input[0] == '/')
		return (0);

	return (-1);
}

/**
 * check_env - check if input is env
 * @input: string to be check
 * Return: 1 if success else 0;
 */

int check_env(char *input)
{
	int i;
	char *env;

	i = 0;
	env = "env";
	if (_strlen(input) != 4)
		return (0);
	while (env[i] != '\0')
	{
		if (env[i] != input[i])
			return (0);
		i++;
	}
	return (1);
}
