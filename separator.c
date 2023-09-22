#include "shell.h"

/**
 *commas_separator - Separates command recieved from stdin by ;
 * @user_input: String inputted by the user
 * Return: Parsed strings to be used as commands
 */

char **commas_separator(char *user_input)
{
	char **cmds;
	char *cmd;
	int i;
	int bsize = BUFFSIZE;

	if (user_input[0] == ' ' && user_input[_strlen(user_input)] == ' ')
		exit(0);
	if (user_input == NULL)
		return (NULL);
	cmds = malloc(sizeof(char *) * bsize);
	if (!cmds)
	{
		free(cmds);
		return (NULL);
	}
	cmd = tokenizer(user_input, ";&");
	for (i = 0; cmd; i++)
	{
		cmds[i] = cmd;
		cmd = tokenizer(NULL, ";&");
	}
	cmds[i] = NULL;

	return (cmds);
}
