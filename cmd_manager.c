#include "shell.h"

/**
 * cmd_parser - function to parse the command line input
 * @userinput: string input by the user
 * Return: Parsed strings to be used as arguments
 */
char **cmd_parser(char *userinput)
{
	char **arguments;
	char *argument;
	int i;
	int bsize = BUFFSIZE;

	if (userinput[0] == ' ' && input[_strlen(userinput)] == ' ')
		exit(0);
	if (userinput == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * bsize);
	if (!arguments)
	{
		free(arguments);
		return (NULL);
	}
	argument = tokenizer(userinput, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = tokenizer(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}


/**
 * cmd_exec - function to execute command process
 * @cmd: buffers  strings
 * @input: user input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv: command line args
 * Return:  -1 if error 0 success
 */
int cmd_exec(char **cmd, char *userinput, int c, char **argv)
{
        int wstatus;
        pid_t pid;

        if (*cmd == NULL)
                return (EXIT_FAILURE);
        pid = fork();
        if (pid == -1)
        {
                perror("./shell: No such file or directory");
                return (-1);
        }
        if (pid == 0)
        {
                if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
                        cmd_parser(cmd);
                if (access(cmd[0], R_OK) != 0)
                {
                        errormessage(cmd[0], c, argv);
                        _free(cmd, userinput);
                        exit(127);
                }
                if (execve(*cmd, cmd, environ) == -1)
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
~
