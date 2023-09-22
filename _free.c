#include "shell.h"

/**
 * _free - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void _free(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
