#include "shell.h"

/**
 * h_all - Displays all possible builtin shellby commands
 */
void h_all(void)
{
	char *msg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * h_alias - Displays information on the shell by builtin command 'alias'
 */
void h_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * h_cd - Displays information on the shell by builtin command 'cd'
 */
void h_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "after a change of directory.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * h_exit - Displays information on the shell by builtin command 'exit'
 */
void h_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * h_help - Displays information on the shell by builtin command 'help'
 */
void h_help(void)
{
	char *msg = "help: help\n\tSee all Shell buildin cmds.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n      help [BUILDIN NAME]\n\tSee specific info on each ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}


/**
 * h_env - Displays information on the shell by builtin command 'env'
 */
void h_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

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
