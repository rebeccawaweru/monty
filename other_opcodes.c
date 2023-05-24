#include "monty.h"

/**
 * add - add top two elements
 * @stack: the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = NULL;
	int total = 0;

	c_stack = *stack;
	if (c_stack == NULL || c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	total = c_stack->n + c_stack->next->n;
	c_stack->next->n = total;
	pop(stack, line_number);
}

/**
 * nop - nop implementation
 * @stack: the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
