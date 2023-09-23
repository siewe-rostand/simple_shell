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

int main(__attribute__((unused)) int argc, char **argv)
{
	char *user_input, **cmd, **cmds;
	int counter = 0, i = 0, status = 0;

	if (argv[1] != NULL)
		file_cmd(argv[1], argv);
	signal(SIGINT, signal_to_handle);
	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt("$: ");
		user_input = _get_line();
		if (user_input[0] == '\0')
			continue;
		shell_history(user_input);
		cmds = commas_separator(user_input);
		for (i = 0; cmds[i] != NULL; i++)
		{
			cmd = parse_string(cmds[i]);
			if (_strcmp(cmd[0], "exit") == 0)
			{
				free(cmds);
				buildin_exit(cmd, user_input, argv, counter, status);
			}
			else if (buildin_checker(cmd) == 0)
			{
				status = buildin_handler(cmd, status);
				free(cmd);
				continue;
			}
			else
				status = fork_wait(cmd, user_input, counter, argv);
			free(cmd);
		}
		free(user_input);
		free(cmds);
		wait(&status);
	}
	return (status);
}
