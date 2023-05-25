#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define DELIMETER " \t\n"
#define MAX_LENGTH 256

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description : opcode and its function for stack, 7queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_v - variables
 * @argument: arguments
 * @f: monty file
 * @c: contents of a line
 * @flg: flag
 * Description: pass values 
 */
typedef struct global_v
{
	char *argument;
	FILE *f;
	char *c;
	int flg;
} global_t;
extern global_t carrier;

void startplus(stack_t **top, int val);
void queueplus(stack_t **top, int val);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void subtraction(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void multiplication(stack_t **stack, unsigned int line_number);
void modular(stack_t **stack, unsigned int line_number);
void prntchar(stack_t **stack, unsigned int line_number);
void prntstrng(stack_t **stack, unsigned int line_number);
void rotatetop(stack_t **stack, unsigned int line_number);
void rotatebottom(stack_t **stack, unsigned int line_number);

int check_integer(char *strng);
char *parse(char *input, stack_t **stack, unsigned int num_line);
void free_mem_stack(stack_t *stack);
void bytecode_exec(FILE *file, stack_t **stack);
typedef void(*fc_instrct)(stack_t **stack, unsigned int line_number);
int op_instruction(char *c, stack_t **stack, unsigned int line_counter, FILE *f);
char *nextArg(char *line);
char *token_acq(char *line, unsigned int num_line);

#endif
