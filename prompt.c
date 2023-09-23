#include "shell.h"

/**
 * prompt - function containing the shell prompt
 *
 * @ch: character to be output
 * Return: the promted int
 */

void prompt(char *ch)
{
	write(STDERR_FILENO, ch, _strlen(ch));
}
