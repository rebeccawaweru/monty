#include "monty.h"

/**
 * check_integer - function to check for decimal digit in character
 * @strng: the string character passed
 * Return: 1 if integer else 0
 */
int check_integer(char *strng)
{
	int j = 0;

	if (!strng)
		return (0);
	if (strng[j] == '-')
		j++;
	if (*(strng + j) != '\0')
	{
		if (*(strng + j) >= '0' && *(strng + j) <= '9')
			j++;
		else
			return (0);
	} else
		return (0);
	return (1);
}
