#include "shell.h"

/**
 * fork_wait - fork child process
 * @cmd: commands to be parse
 * @userinput: user input
 * @counter: execution counter
 * @argv: Arguments variable
 * Return: 1 on Null -1 on error 0 on success
 */
int fork_wait(char **cmd, char *userinput, int counter, char **argv)
{
	int wstatus;
	pid_t child_pid;

	if (*cmd == NULL)
		return (EXIT_FAILURE);
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./shell: No such file or directory");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
			path_exec(cmd);
		if (access(cmd[0], R_OK) != 0)
		{
			errormessage(cmd[0], counter, argv);
			_free(cmd, userinput);
			exit(127);
		}
		if (execve(*cmd, cmd, ENV) == -1)
			return (2);
		else
			return (0);
	}
	wait(&wstatus);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
			return (0);
		else if (WEXITSTATUS(wstatus) == 2)
			return (2);
		else if (WEXITSTATUS(wstatus) == 127)
			return (127);
	}
	return (127);
}
