#include "shell.h"

/**
 * file_error_message - function to print file custom error
 * @argv: Arguments variables
 * @counter: count error
 */
void file_error_message(char **argv, int counter)
{
        char *er = _itoc(counter);

        prompt(argv[0]);
        prompt(": ");
        prompt(er);
        prompt(": Can't open ");
        prompt(argv[1]);
        prompt("\n");
        free(er);
}


/**
 * errormessage - Displays error message
 * @input: user input
 * @counter: loop counter
 * @argv: Arguments variables
 */

void errormessage(char *input, int counter, char **argv)
{
        char *error;

        prompt(argv[0]);
        prompt(": ");
        error = _itoc(counter);
        prompt(error);
        free(error);
        prompt(": ");
        prompt(input);
        prompt(": No such file or directory\n");
}

/**
 *  _prerror - function to print some custom errors to user
 * @argv: Arguments variables
 * @counter: for counting errors
 * @cmd: cmds of  parsed  strings
 */

void _prerror(char **argv, int counter, char **cmd)
{
	char *er = _itoc(counter);

	prompt(argv[0]);
	prompt(": ");
	prompt(er);
	prompt(": ");
	prompt(cmd[0]);
	prompt(": number is not legal: ");
	prompt(cmd[1]);
	prompt("\n");
	free(er);
}
