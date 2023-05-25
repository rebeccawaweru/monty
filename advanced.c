#include "monty.h"

/**
 * modular - function to compute rest of division
 * @stack: the stack
 * @line_number: the line number
 */
void modular(stack_t **stack, unsigned int line_number)
{
	int mod = 0;
	stack_t *c_stack = NULL;

	c_stack = *stack;
	while (c_stack == NULL || c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (c_stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	mod = c_stack->next->n % c_stack->n;
	c_stack->next->n = mod;
	pop(stack, line_number);
}
/**
 * prntchar - function to print the character at the top
 * @stack: the stack
 * @line_number: the line_number
 */
void prntchar(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = NULL;

	c_stack = *stack;
	if (c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (c_stack->next->n > 127 || c_stack->next->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * prntstrng - function to print the string at the top
 * @stack: the stack
 * @line_number: the line number
 */
void prntstrng(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = NULL;

	(void)line_number;

	c_stack = (*stack)->next;
	if ((c_stack->n > 0 && c_stack->n <= 127) && c_stack && c_stack->n != 0)
	{
		printf("%c", c_stack->n);
		c_stack = c_stack->next;
	}
	printf("\n");
}
/**
 * rotatetop - function for rotating the top value
 * @stack: the stack
 * @line_number: line number
 */
void rotatetop(stack_t **stack, unsigned int line_number)
{
	stack_t *lead = NULL;
	stack_t *finish = NULL;
	stack_t *c_stack = NULL;

	(void)line_number;
	c_stack = (*stack)->next;
	if (c_stack == NULL || c_stack->next == NULL)
		return;
	lead = c_stack;
	finish = c_stack;
	if (finish->next != NULL)
		finish = finish->next;
	lead->next->prev = *stack;
	c_stack = lead->next;
	finish->next = lead;
	lead->next = NULL;
	lead->next = finish;
}
/**
 * rotatebottom - function for rotating the bottom value
 * @stack: the stack
 * @line_number: line number
 */
void rotatebottom(stack_t **stack, unsigned int line_number)
{
	stack_t *lead = NULL;
	stack_t *finish = NULL;
	stack_t *c_stack = NULL;

	(void)line_number;
	c_stack = (*stack)->next;
	if (c_stack == NULL || c_stack->next == NULL)
		return;
	lead = c_stack;
	finish = c_stack;
	if (finish->next != NULL)
		finish = finish->next;
	finish->prev->next = NULL;
	c_stack = finish;
	finish->prev = *stack;
	finish->next = lead;
	lead->prev = finish;
}
