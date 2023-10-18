#include "shell.h"

/**
 * interactive - It returns trueif shell is in interactive mode
 * @info: Structure address
 *
 * Return: If interactive mode 1, if not 0.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _isalpha - It checks for alphabetic char
 * @c: The char to input
 * Return: If c is alphabetic 1, if not 0.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - It converts a string to an integer
 * @s: The string to be converted
 * Return: If no numbers in string 0, if otherwise converted number
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * is_delim - It checks if char is a delimeter
 * @c: The char to check
 * @delim: The delimeter string
 * Return: If true 1, if false 0.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
