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
	size_t len_line;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		num_line++;
		len_line = strlen(line);
		if (line[len_line - 1] == '\n')
			line[len_line - 1] = '\0';
		opcode = token_acq(line, num_line);
		if (opcode != NULL)
			op_instruction(opcode, &stack, num_line);
		else
			continue;
	}
	free_mem_stack(stack);
	fclose(file);
}
