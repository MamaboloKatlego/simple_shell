#include "shell.h"

/**
 * _strlen - It returns the length of a string
 * @s: String whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * starts_with - It checks if needle starts with haystack
 * @haystack: The string to search
 * @needle: Substring to find
 *
 * Return: The address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - It concatenates two strings
 * @dest: Destination buffer
 * @src: Source buffer
 *
 * Return: The pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strcmp - It performs lexicogarphic comparison of two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: If s2 > s1 negative, if s2 < s1 positive, if s2 == s1 zero
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
