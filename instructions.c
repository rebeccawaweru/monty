#include "monty.h"

/**
 * op_instruction - link opcode to the one in the user input
 * @input: user input
 * @stack: the stack
 * @line_number: the bytecode line number
 * Return: pointer or NULL
 */
void op_instruction(char *input, stack_t **stack, unsigned int line_number)
{
	int x = 0;

	instruction_t get_instrct[] = {
		{"push", push},
		{"pull", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}
	};
	if (get_instrct[x].opcode != NULL)
	{
		while (strcmp(get_instrct[x].opcode, input) == 0)
		{
			get_instrct[x].f(stack, line_number);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, input);
	exit(EXIT_FAILURE);
}
