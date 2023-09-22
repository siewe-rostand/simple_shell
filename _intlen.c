#include "shell.h"

/**
 * _intlen - function that determine length of integer
 * @num: given integer
 * Return: length of integer
 */

int _intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
