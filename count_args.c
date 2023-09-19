#include "shell.h"

/**
 * count_args - count the args user input
 * @input: string inputed by the user
 *
 * Return: number of arguments
 */

int count_args(char *input)
{
	int i = 0;
	int args = 1;
	int begin = 0;

	while (input[i] != '\0' && input[i] != '\n')
	{
		if (input[i] != ' ')
			begin = 1;
		if (input[i] == ' ' && input[i + 1] != ' ' && input[i + 1] != '\n'
				&& begin == 1)
			args++;
		i++;
	}
	return (args);
}
