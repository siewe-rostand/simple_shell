#include "shell.h"

/**
 * env_creation - env variables creations
 * @envi: variable used to store env variables
 */

void env_creation(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}

/**
 * free_environ - created environment variables memory free
 * @env:  environtment variables arrays
 */
void free_environ(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
