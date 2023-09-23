#include "shell.h"

/**
 * _get_line - function to get user input
 *
 * Return: input string
 */

char *_get_line(void)
{
	int i, read_string, buffersize;
	char *buffer, *new_buffer, c = 0;

	buffersize = BUFFSIZE;
	buffer = malloc(buffersize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		read_string = read(STDIN_FILENO, &c, 1);
		if (read_string == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (handle_newline(buffer));
		if (i >= buffersize)
		{
			buffer = _realloc(buffer, buffersize, (buffersize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	new_buffer = remove_space(buffer);
	free(buffer);
	handle_comment(new_buffer);
	return (new_buffer);
}
