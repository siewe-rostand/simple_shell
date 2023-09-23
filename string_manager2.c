#include "shell.h"


/**
 * _strlen - string length
 *
 * @str: param
 *
 * Return: int
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}


/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

