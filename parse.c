#include "monty.h"

/**
 * parse - parse input for opcodes
 * @input: line input
 * @stack: the stack
 * @num_line: the line number
 * Return: opcode or null
 */
char *parse(char *input, stack_t **stack, unsigned int num_line)
{
	int v_global;
	char *code, *argument;
	char *p = "push";
	(void)stack;

	code = strtok(input, "\n ");
	if (code == NULL)
		return (NULL);
	while (strcmp(code, p) == 0)
	{
		argument = strtok(NULL, "\n ");
		if (check_integer(argument) == 1 && argument != NULL)
		{
			v_global = atoi(argument);
			printf("%d", v_global);
		} else
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			exit(EXIT_FAILURE);
		}
	}
	return (code);
}
