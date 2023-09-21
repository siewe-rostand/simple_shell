#include "shell.h"

/**
 * handle_newline - handle newline character input
 * @str: string buffer to be handle
 * Return: Empty string
 */

char *handle_newline(char *str)
{
	free(str);
	return ('\0');
}
