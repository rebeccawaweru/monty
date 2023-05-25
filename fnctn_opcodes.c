#include "monty.h"

/**
 * push - function to add element to stack
 * @stack: the stack
 * @line_number: line number in the monty byte code file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int a, b = 0, fg = 0;

	if (carrier.argument)
	{
		if (carrier.argument[0] == '-')
			b++;
		for (; carrier.argument[b] != '\0'; b++)
		{
			if (carrier.argument[b] > 57 || carrier.argument[b] < 48)
				fg = 1;
		}
		if (fg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(carrier.f);
			free(carrier.c);
			free_mem_stack(*stack);
			exit(EXIT_FAILURE);
		}
	} else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(carrier.f);
		free(carrier.c);
		free_mem_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = atoi(carrier.argument);
	if (carrier.flg == 0)
		startplus(stack, a);
	else
		queueplus(stack, a);
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
