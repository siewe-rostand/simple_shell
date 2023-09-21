#include "shell.h"

/**
 * main - main function of the simple shell
 *
 * @argc: number of arguments passed
 * @argv: pointer array pointing to argument passed
 * @env: environment variable
 *
 * Return: return 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *user_input = NULL, **cmd = NULL, **cmds =  NULL;
	int count = 0, i, st = 0;

	(void)argc; (void)argv;
	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		user_input = _get_line();
		if (user_input[0] == '\0')
			continue;
		for (i = 0; cmd[i] != NULL; i++)
		{
			cmd = parse_string(cmds[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(cmds);
			}
			else
				st = fork_wait(cmd, user_input, env);
			free(cmd);
		}
		free(user_input);
		free(cmds);
		wait(&st);
	}
	return (st);
}
