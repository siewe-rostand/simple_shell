#include "shell.h"

/**
 * prompt_num - print an integer
 * @n: integer to be printed
 */

void prompt_num(int n)
{
	int digit, sum, last;
	int divis = 1000000000;
	unsigned int num;

	num = n;
	sum = 0;

	while (divis > 1)
	{
		digit = (num / divis) % 10;
		sum += digit;
		if (sum != 0)
			_putchar(digit + '0');
		divis = divis / 10;
	}

	last = num % 10;
	_putchar(last + '0');
}


