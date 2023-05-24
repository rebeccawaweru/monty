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
		while (line[j] != ' '  && line[j] != '\t'
		&& line[j] != '\n' && line[j] != '\0')
			j++;
		line[j] = '\0';
	}
	return (argument);
}

/**
 * push - function to add element to stack
 * @stack: the stack
 * @line_number: line number in the monty byte code file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *fresh_node = NULL;

	(void) line_number;
	fresh_node = malloc(sizeof(stack_t));
	if (!fresh_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	fresh_node->n = v_global;
	fresh_node->prev = NULL;
	if (*stack == NULL)
	{
		fresh_node->next = NULL;
		*stack = fresh_node;
		return;
	}
	fresh_node->next = *stack;
	(*stack)->prev = fresh_node;
	*stack = fresh_node;
}

/**
 * pall - function to print all values on the stack
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = *stack;

	(void) line_number;
	if (*(stack) == NULL)
		return;
	while (c_stack)
	{
		printf("%d\n", c_stack->n);
		c_stack = c_stack->next;
	}
}
