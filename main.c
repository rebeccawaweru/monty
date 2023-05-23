#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: holds the arguments
 * Return: exit status
 */
int main(int argc, char *argv[])
{
	char *name = argv[1];
	FILE *file = fopen(name, "r");

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	bytecode_exec(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
