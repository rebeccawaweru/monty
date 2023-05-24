#include "monty.h"

/**
 * token_acq - function to get token of the line
 * @line: user line
 * @num_line: user line number
 * Return: line number
 */
char *token_acq(char *line, unsigned int num_line)
{
	char *t = NULL;
	char delimeter[2] = "\n";
	char *x = NULL;
	int v_global;

	t = strtok(line, delimeter);
	if (!t)
		return (NULL);
	x = strtok(NULL, delimeter);
	if (x != NULL)
	{
		if (check_integer(x))
		{
			v_global = atoi(x);
			printf("%d", v_global);
		} else
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			exit(EXIT_FAILURE);
		}
	} else if (x == NULL && strcmp(t, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	return (t);
}
