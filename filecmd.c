#include "shell.h"

/**
 * file_cmd - function to read cmd from file
 * @file: the file with the cmd to be executed
 * @argv: Arguments passed
 * Return: -1 or 0
 */

void file_cmd(char *file, char **argv)
{
	FILE *file_path;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	file_path = fopen(file, "r");
	if (file_path == NULL)
	{
		file_error_message(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, file_path)) != -1)
	{
		count++;
		treat_file(line, count, file_path, argv);
	}
	if (line)
		free(line);
	fclose(file_path);
	exit(0);
}
