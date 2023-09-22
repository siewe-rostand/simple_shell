#include "shell.h"

/**
 * handle_delimiter - function that checks if a character matchs any character
 * @ch: character to be check
 * @del: delimiters to the string
 * Return: 1 on success, 0 on failure
 */
unsigned int handle_delimiter(char ch, const char *del)
{
	unsigned int i;

	for (i = 0; del[i] != '\0'; i++)
	{
		if (ch == del[i])
			return (1);
	}
	return (0);
}
