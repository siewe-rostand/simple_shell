#include "shell.h"

/**
 * handle_comment - function to handle comment
 * @buffer: input string
 * Return: void
 */

void handle_comment(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
			buffer[i] = '\0';
	}
}
