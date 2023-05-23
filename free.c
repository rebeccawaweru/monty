#include "monty.h"

/**
 * free_stack - function to remove stack from memory
 * @stack: the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *c_stack = stack;

	while (c_stack)
	{
		stack_t *x = c_stack;

		c_stack = c_stack->next;
		free(x);
	}
}
