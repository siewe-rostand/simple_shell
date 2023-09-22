#include "shell.h"

/**
 * buildin_checker - function to check parse input cmd
 * @cmd: input cmd to be parse
 * Return: 0 Succes -1 on error
 */
int buildin_checker(char **cmd)
{
	buildin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * buildin_handler - function to handle some predefine cmds
 * @cmd: some parsed commands
 * @st:  last execution status
 * Return: -1 Failure 0 on Success
 */
int buildin_handler(char **cmd, int st)
{
	buildin build_in[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((build_in + i)->command)
	{
		if (_strcmp(cmd[0], (build_in + i)->command) == 0)
		{
			return ((build_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}
