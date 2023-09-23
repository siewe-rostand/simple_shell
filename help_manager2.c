#include "shell.h"

/**
 * h_setenv - Displays information on the shell by builtin command 'setenv'
 */
void h_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * h_unsetenv - Displays information on the shellby builtin command
 * 'unsetenv'
 */
void h_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * show_help - show help for buildin cmds
 * @cmd: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int show_help(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		h_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		h_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		h_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		h_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		h_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		h_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		h_unsetenv();
	else if (_strcmp(cmd[1], "help") == 0)
		h_help();
	return (0);
}

/**
 * h_env - Displays information on the shell by builtin command 'env'
 */
void h_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

