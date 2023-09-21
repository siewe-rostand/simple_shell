#include "shell.h"

/**
 * remove_space - remove space from input string
 * @str: input string to be modified
 * Return: return string that has been modified
 */

char *remove_space(char *str)
{
	int i, j;
	char *buffer;

	buffer = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buffer[j] = str[i];
		j++;
	}
	buffer[j] = '\0';
	if (buffer[0] == '\0' || buffer[0] == '#')
	{
		free(buffer);
		return ("\0");
	}
	return (buffer);
}
