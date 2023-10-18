#include "shell.h"

/**
 * ffree - It frees a string of strings
 * @pp: The string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - It reallocates a block of memory
 * @ptr: The pointer to the past malloc'ated block
 * @old_size: The byte size of the past block
 * @new_size: The byte size of new block
 *
 * Return: The pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * _memset - It fills memory with a constant byte
 * @s: The pointer to the memory area
 * @b: The byte to fill *s with
 * @n: Amount of bytes to be filled
 * Return: The (s) a pointer to the memoryares s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
