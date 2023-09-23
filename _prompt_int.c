#include "shell.h"

/**
 * prompt_int - Prints integers using _putchar function
 * @num: Integer to be printed
 */
void prompt_int(int num)
{
	unsigned int x = num;

	if (num < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		prompt_num(x / 10);

	_putchar(x % 10 + '0');
}
