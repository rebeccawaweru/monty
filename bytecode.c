#include "monty.h"
/**
 * bytecode_exec - monty bytecode execution
 * @file: the file to be executed
 * @stack: the top of stack
 */
void bytecode_exec(FILE *file, stack_t **stack)
{
	char line[MAX_LENGTH];
	char *opcode = NULL;
	fc_instrct b;
	int close;
	int count = 1;
	char *buf = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		opcode = parse(buf, stack, count);
		if (opcode == NULL || opcode[0] == '#')
		{
			count++;
			continue;
		};
		b = op_instruction(opcode);
		if (b == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", count, opcode);
			exit(EXIT_FAILURE);
		}
		b(stack, count);
		count++;
	}
	free_mem_stack(*stack);
	close = fclose(file);
	if (close == -1)
		exit(-1);
}
