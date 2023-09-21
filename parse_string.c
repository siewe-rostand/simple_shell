#include "shell.h"

/**
 * parse_string - Parses the command recieved from stdin
 * @user_input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */

char **parse_string(char *user_input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFFSIZE;

	if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
		exit(0);
	if (user_input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = _strtok(user_input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = _strtok(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}
