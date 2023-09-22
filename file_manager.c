#include "shell.h"

/**
 * file_exit_status - function to handle exit status of a file
 * @line: file line counter
 * @cmd: command that is parsed
 * @filepath: file path
 */
void file_exit_status(char **cmd, char *line, FILE *filepath)
{
        int status;
        int i = 0;

        if (cmd[i] == NULL)
        {
                free(line);
                free(cmd);
                fclose(filepath);
                exit(errno);
        }
        while (cmd[1][i])
        {
                if (_isalpha(cmd[1][i++]) < 0)
                        perror("number is nor legal");
        }
        status = _atoi(cmd[1]);
        free(line);
        free(cmd);
        fclose(filepath);
        exit(status);
}


/**
 * treat_file - function to parse and handle cmds
 * @line: file line count
 * @count: error in file count
 * @fp: file path
 * @argv: Command line arguments
 */

void treat_file(char *line, int count, FILE *filepath, char **argv)
{
        char **cmd;
        int stat = 0;

        cmd = parse_string(line);
        if (_strncmp(cmd[0], "exit", 4) == 0)
                file_exit_status(cmd, line, fp);
        else if (buildin_checker(cmd) == 0)
        {
                stat = buildin_handler(cmd, stat);
                free(cmd);
        }
        else
        {
                stat = cmd_exec(cmd, line, count, argv);
                free(cmd);
        }
}
