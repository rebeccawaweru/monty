#include "monty.h"

/**
 * free_mem_stack - function to remove stack from memory
 * @stack: the stack
 */
void free_mem_stack(stack_t *stack)
{
	stack_t *c_stack;

	while (stack)
	{
		c_stack = stack->next;
		free(stack);
		stack = c_stack;
	}
}
