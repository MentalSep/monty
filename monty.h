#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global variables
 * @opBuffer: buffer to store the opcode
 * @file: file pointer
 * @line_number: line number
 * @stack: pointer to the stack
 *
 * Description: global variables
 */
typedef struct global_s
{
	char **opBuffer;
	FILE *file;
	int line_number;
	stack_t *stack;
} global_t;

global_t gData;

char **getInstructions(char *line);
void (*validOpCode(char *opCode)) (stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif /* MONTECARLO_H */