#include "monty.h"

/**
 * op_instruction - link opcode to the one in the user input
 * @strng: opcodes
 * Return: functions or NULL
 */
fc_instrct op_instruction(char *strng)
{
	int x = 0;

	instruction_t get_instrct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	if (get_instrct[x].f != NULL && strcmp(get_instrct[x].opcode, strng) != 0)
		x++;
	return (get_instrct[x].f);
}
