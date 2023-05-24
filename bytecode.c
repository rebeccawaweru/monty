#include "monty.h"
/**
 * bytecode_exec - monty bytecode execution
 * @file: the file to be executed
 */
void bytecode_exec(FILE *file)
{
	stack_t *stack = NULL;
	char line[MAX_LENGTH];
	unsigned int num_line = 0;
	char *opcode = NULL;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		num_line++;
		opcode = token_acq(line, num_line);
		if (opcode != NULL)
			op_instruction(opcode, &stack, num_line);
	}
	free_mem_stack(stack);
	fclose(file);
}
