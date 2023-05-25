#define _POSIX_C_SOURCE 200809L

#include "monty.h"
global_t carrier = {NULL, NULL, NULL, 0};

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: holds the arguments
 * Return: 0 on success else 1
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *name = argv[1];
	FILE *file = fopen(name, "r");
	unsigned int line_counter = 0;
	ssize_t ln = 1;
	size_t sz = 0;
	char *material;
	int close;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	carrier.f = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	while (ln > 0)
	{
		material = NULL;
		ln = getline(&material, &sz, file);
		carrier.c = material;
		line_counter++;
		if (ln > 0)
			op_instruction(material, &stack, line_counter, file);
		free(material);
	}
	free_mem_stack(stack);
	close = fclose(file);
	if (close == -1)
		exit(-1);
	return (EXIT_SUCCESS);
}
