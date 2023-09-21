#include "shell.h"

/**
 * check_delim - function that checks if a character matchs any character
 * @c: character to check
 * @str: string of delimiters
 * Return: 1 on success, 0 on failure
 */

unsigned int check_delim(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}
