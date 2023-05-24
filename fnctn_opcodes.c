#include "monty.h"

/**
 * push - function to add element to stack
 * @stack: the stack
 * @line_number: line number in the monty byte code file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *fresh_node = NULL;
	int v_global = 0;

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

/**
 * pint - prints top value
 * @stack: the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	c_stack = *stack;
	printf("%d\n", c_stack->n);
}

/**
 * pop - function to remove top element
 * @stack: the stack
 * @line_number: the line_number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *c_stack;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	c_stack = *stack;
	*stack = c_stack->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(c_stack);
}

/**
 * swap - switch two elements at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *lead = NULL;
	stack_t *follow = NULL;

	lead = *stack;
	if (lead == NULL || lead->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	follow = (*stack)->next;
	lead->prev = follow;
	follow->prev = NULL;
	lead->next = follow->next;
	follow->next = lead;

	*stack = follow;
}
