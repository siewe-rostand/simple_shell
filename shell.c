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
	char *user_input, **cmd, **cmds;
	int counter = 0, i = 0, status = 0;

	if (argv[1] != Null)
		fiel_cmd(argv[1], argv);
	(void)argc; (void)argv;
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		user_input = _get_line();
		if (user_input[0] == '\0')
			continue;
		while (cmd[i] != NULL)
		{
			cmd = parse_string(cmds[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(cmds);
				buildin_exit(cmd, user_input, argv, counter, status);
			}else if (buildin_checker(cmd) == 0)
			{
				status = buildin_handler(cmd, status);
				free(cmd);
				continue;
			}
			else
				status = fork_wait(cmd, user_input, env);
			free(cmd);
			i++;
		}
		free(user_input);
		free(cmds);
		wait(&status);
	}
	return (status);
}
