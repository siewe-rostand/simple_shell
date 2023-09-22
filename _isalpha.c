#include "shell.h"

/**
 * _isalpha - function to check if c is alphabet
 * @ch: character to check
 * Return: 1 if true 0 if false
 */
int _isalpha(int ch)
{
	if (((ch >= 97) && (ch <= 122)) || ((ch >= 65) && (ch <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
