#include "shell.h"

/**
 * _get_env - function to get environment variable
 * @name: name passed to get the variable
 * Return: the environment variable or NULL if error
 */
char *_get_env(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_len) == 0)
		{
			value_len = _strlen(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("Error: memory allocation error");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}
