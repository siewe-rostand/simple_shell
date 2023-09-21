#include "shell.h"

/**
 * free_buffer - function to free string buffers
 * @buffer: buffer to be free
 * Return: nothing
 */

void free_buffer(char **buffer)
{
	size_t i;

	for (i = 0; buffer[i] != '\0'; i++)
		free(buffer[i]);

	free(buffer);
