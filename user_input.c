#include "shell.h"

/**
 * get_user_string - get the user input string
 *
 * @rvalue: return value from getline function
 *
 * Return: user input string
 */

char *get_user_string(int *rvalue)
{
	char *user_input = NULL;
	size_t bsize = 0;

	*rvalue = getline(&user_input, &bsize, stdin);

	return (user_input);
}
