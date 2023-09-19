#include "shell.h"

/**
 * _strlen - string length
 *
 * @s: param
 *
 * Return: int
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length] != 0)
	{
		length++;
	}

	return (length);
}
