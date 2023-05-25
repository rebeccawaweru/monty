#include "monty.h"

/**
 * op_instruction - executing the instruction from opcode
 * @c: content of the line
 * @f: file
 * @line_counter: counter
 * @stack: the top of the stack
 *
 * Return: functions or NULL
 */
int op_instruction(char *c, stack_t **stack,
	unsigned int line_counter, FILE *f)
{
	int x = 0;
	char *code;

	instruction_t get_instrct[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", subtraction},
		{"div", division},
		{"mul", multiplication},
		{"mod", modular},
		{"pchar", prntchar},
		{"pstr", prntstrng},
		{"rotl", rotatetop},
		{"rotr", rotatebottom},
		{NULL, NULL}
	};
	code = strtok(c, DELIMETER);
	if (code && code[0] == '#')
	{
		;
	}
	carrier.argument = strtok(NULL, DELIMETER);
	while (get_instrct[x].opcode && code)
	{
		if (strcmp(code, get_instrct[x].opcode) == 0)
		{
			get_instrct[x].f(stack, line_counter);
			return (0);
		}
		x++;
	}
	if (code && get_instrct[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, code);
		fclose(f);
		free(c);
		free_mem_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
