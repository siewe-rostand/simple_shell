#include "shell.h"

/**
 * doubleptr_realloc - double ptr memory reallocation
 * @dbptr: double ptr to be reallocated
 * @old_size: old ptr size
 * @new_size: new ptr size
 * Return: new ptr
 */

char **doubleptr_realloc(char **dbptr, unsigned int old_size,
		unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (dbptr == NULL)
		return (malloc(sizeof(char *) * new_size));
	if (new_size == old_size)
		return (dbptr);
	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < old_size; i++)
		newptr[i] = dbptr[i];

	free(dbptr);

	return (newptr);
}
