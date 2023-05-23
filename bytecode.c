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
		opcode = nextArg(line);
		if (!opcode)
			continue;
		if (strcmp(opcode, "push") == 0)
			push(&stack, num_line, line);
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", num_line, opcode);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
}
