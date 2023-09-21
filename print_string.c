#include "shell.h"

/**
 * print_string - function that enable to print a string
 * @str: input string
 * Return: nothing
 */

void print_string(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i] != '\0')
	{
		count += _putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
