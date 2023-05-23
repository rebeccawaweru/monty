#include "monty.h"

/**
 * nextArg - function to get next argument
 * @line: the line
 * Return: argument
 */
char *nextArg(char *line)
{
	char *argument = NULL;
	int j = 0;

	while (line[j] == ' ' || line[j] == '\t')
		j++;
	if (line[j] != '\0')
	{
		argument = &line[j];
		while (line[j] != ' '  && line[j] != '\t' && line[j] != '\n' && line[j] != '\0')
			j++;
		line[j] = '\0';
	}
	return argument;
}

/**
 * push - function to add element to stack
 * @stack: the stack
 * @num_line: line number in the monty byte code file
 * @line: the line
 */
void push(stack_t **stack, unsigned int num_line, char *line)
{
	int val = 0;
	char *argument = NULL;
	stack_t *fresh_node = NULL;

	/*check for argument*/
	if (!num_line || !stack)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	argument = nextArg(line);
	if (!argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (!check_integer(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	val = atoi(argument);
	if (val == 0 && argument[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	fresh_node = malloc(sizeof(stack_t));
	if (!fresh_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fresh_node->n = val;
	fresh_node->prev = NULL;
	fresh_node->next = *stack;
	if (*stack)
		(*stack)->prev = fresh_node;
	*stack = fresh_node;
}

/**
 * pall - function to print all values on the stack
 * @stack: the stack
 */
void pall(stack_t **stack)
{
	stack_t *c_stack = *stack;
	if (!stack)
		return;
	while (c_stack)
	{
		printf("%d\n", c_stack->n);
		c_stack = c_stack->next;
	}
}
