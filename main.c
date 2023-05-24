#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: holds the arguments
 * Return: 0 on success else 1
 */
int main(int argc, char *argv[])
{
	char *name = argv[1];
	FILE *file = fopen(name, "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	} else if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	} else
		bytecode_exec(file);
	return (EXIT_SUCCESS);
}
