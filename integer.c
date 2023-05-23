#include "monty.h"

/**
 * check_integer - function to check for decimal digit in character
 * @strng: the string character passed
 * Return: 1 if integer else 0
 */
int check_integer(const char *strng)
{
	if (!strng)
		return (0);
	if (*strng == '-' || *strng == '+')
		strng++;
	if (*strng == '\0')
		return (0);
	while (*strng)
	{
		if (!isdigit((unsigned char)*strng))
			return (0);
		strng++;
	}
	return (1);
}
