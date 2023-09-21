#include "shell.h"

/**
 * get_input - function to get user input
 *
 * Return: input string
 */

void *_get_line(void)
{
	int i, read_string, buffersize = BUFFSIZE;
	char c = 0, *buffer, *new_buffer;

	buffer = malloc(buffersize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n; i++)
	{
		fflush(stdin);
		read_string = read(STDIN_FILEO, &c, 1);
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
			buffer = _realloc(buffer, buffersize, (buffersize +2));
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
	return (new_buffer)
}
