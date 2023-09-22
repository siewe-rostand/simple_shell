#include "shell.h"

/**
 * shell_history - create a file to store the user input
 * @userinput: user input
 * Return: 0 on success -1 if error occur
 */
int shell_history(char *userinput)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (userinput)
	{
		while (userinput[len])
			len++;
		w = write(fd, userinput, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
