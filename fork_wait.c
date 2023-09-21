#include "shell.h"

/**
 * fork_wait - fork child process
 * @input: user input
 * @env: arrays of environment variables
 * @argv: array of path
 * @cmd: array of strings
 * Return: nothing
 */

int fork_wait(char **cmd, char *input, char **env)
{
	int wstatus;
	pid_t pid;

	pid = fork();
	wstatus = 0;
	if (pid == -1)
	{
		perror("./shell: No such file or directory");
		exit(1);
	}
	if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
		{
			perror("./shell: No such file or directory");
			free_buffer(cmd, input);
			exit(127);
		}
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
		perror("./shell: No such file or directory");
	return (127);
}
