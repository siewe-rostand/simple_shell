#include "shell.h"

/**
 * free_array - free an array of strings
 * @cmd: array to free
 * @line: char pointer
 */

void free_buffer(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
