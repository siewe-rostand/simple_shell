#include "shell.h"


/**
 * _strcat - function that concatenates two strings
 * @dest: first param
 * @src: second param
 * Return: first string + second string
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}


/**
 * _strcmp - function that compares two string
 * @str1: first string
 * @str2: second string
 * Return: 0 on success
 */
int _strcmp(char *str1, char *str2)
{
	int cmp = 0, i, len1, len2;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			cmp = str1[i] - str2[i];
			break;
		}
		else
			continue;

	}
	return (cmp);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @str1: first string
 * @str2: second string
 * @n: amount of characters to compare
 * Return: 1 on error 0 on success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);

	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string
 * Return: pointer to newly allocated space in memory
 */

char *_strdup(char *str)
{
	int length, i;
	char *arr;

	length = 0;
	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	arr = malloc((length + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		arr[i] = str[i];
	arr[i] = '\0';

	return (arr);
}
