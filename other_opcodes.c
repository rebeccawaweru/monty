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
 * subtraction - function to subtract the top element
 * @stack: the stack
 * @line_number: line number
 */
void subtraction(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = NULL;
	int difference = 0;

	c_stack = *stack;
	while (c_stack == NULL || c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	difference = c_stack->next->n - c_stack->n;
	c_stack->next->n = difference;
	pop(stack, line_number);
}
/**
 * division - function to divide second top element with the first
 * @stack: the stack
 * @line_number: the line number
 */
void division(stack_t **stack, unsigned int line_number)
{
	int divident = 0;
	stack_t *c_stack = NULL;

	c_stack = *stack;
	while (c_stack == NULL || c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (c_stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divident = c_stack->next->n / c_stack->n;
	c_stack->next->n = divident;
	pop(stack, line_number);
}
/**
 * multiplication - function to multiply second top with the top element
 * @stack: the stack
 * @line_number: the line number
 */
void multiplication(stack_t **stack, unsigned int line_number)
{
	int product = 0;
	stack_t *c_stack = NULL;

	c_stack = *stack;
	while (c_stack == NULL || c_stack->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	product = c_stack->next->n * c_stack->n;
	c_stack->next->n = product;
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
