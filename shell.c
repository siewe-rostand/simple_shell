#include "shell.h"

/**
 * main - main function of the simple shell
 *
 * @argc: number of arguments passed
 * @argv: pointer array pointing to argument passed
 *
 * Return: return 0 on success
 */
int main(int argc, char **argv)
{
	char *prompt = "#cisfun$ ";
	char user_input[50];
	int n = sizeof(user_input);

	(void)argv; (void)argc; /*since they have not been used */

	while (1)
	{
		printf("%s", prompt);
		if (fgets(user_input, n, stdin) == NULL)
			break;
		if (_strcmp(user_input, "exit") == 0)
			break;

		if (access(user_input, X_OK) != 0)
			printf("./shell: No such file or directory\n");
	}
	return (0);
}
