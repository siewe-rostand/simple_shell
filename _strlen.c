#include "shell.h"

/**
 * _strlen - string length
 *
 * @s: param
 *
 * Return: int
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
