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
		{"cd", _cd},
		{"env", show_env},
		{"help", show_help},
		{"echo", echo_buildin},
		{"history", cmd_history},
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

/**
 * _echo - function to execute the buiidin echo
 * @cmd: input parsed command
 * Return: 0 on Success -1 on error
 */
int buildin_echo(char **cmd)
{
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                if (execve("/bin/echo", cmd, environ) == -1)
                {
                        return (-1);
                }
                exit(EXIT_FAILURE);
        }
        else if (pid < 0)
        {
                return (-1);
        }
        else
        {
                do {
                        waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        return (1);
}

/**
 * buildin_exit - function to give exit status of buildin cmd
 * @cmd: parsed cmd strings
 * @input: user input
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */
void buildin_exit(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			_prerror(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				_prerror(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);

		}
	}
}



/**
 * echo_buildin - execute echo buildin  cases
 * @st: latest cmd status
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_buildin(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		prompt_int(st);
		print_string("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		prompt_num(pid);
		prompt("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _get_env("PATH");
		prompt(path);
		prompt("\n");
		free(path);
	}
	else
		return (buildin_echo(cmd));

	return (1);
}

/**
 * show_env - function to show enviroment variable
 * @cmd: parsed command
 * @st: latest cmd status
 * Return: Always 0
 */
int show_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}


/**
 * cd - Changes directory
 * @cmd: cmd to be parse
 * @st: latest cmd status
 * Return: 0 on success 1 on error (For OLDPWD Always 0 incase of no OLDPWD)
 */
int _cd(char **cmd, __attribute__((unused))int st)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("shell");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
