#include "shell.h"

/**
 * bfree - It frees a pointer and NULL's the address
 * @ptr: The address of the pointer to free
 *
 * Return: If freed 1, O otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
