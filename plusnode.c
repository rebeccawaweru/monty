#include "monty.h"

/**
 * startplus - put node at the beginning of the stack
 * @top: start of the stack
 * @val: value
 */
void startplus(stack_t **top, int val)
{
	stack_t *fresh_node, *x;

	x = *top;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (x)
		x->prev = fresh_node;
	fresh_node->n = val;
	fresh_node->next = *top;
	fresh_node->prev = NULL;
	*top = fresh_node;
}

/**
 * queueplus - add to the tail
 * @val: value
 * @top: start of the stack
 */
void queueplus(stack_t **top, int val)
{
	stack_t *fresh_node, *x;

	x = *top;
	fresh_node = malloc(sizeof(stack_t));
	if (fresh_node == NULL)
		printf("Error\n");
	fresh_node->n = val;
	fresh_node->next = NULL;
	if (x)
	{
		if (x->next)
			x = x->next;
	}
	if (!x)
	{
		*top = fresh_node;
		fresh_node->prev = NULL;
	} else
	{
		x->next = fresh_node;
		fresh_node->prev = x;
	}
}
