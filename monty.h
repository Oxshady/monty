#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_LINE_CHARS 256
#define MAX_LINES 1000
extern char buffer[MAX_LINE_CHARS];

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
void _add(stack_t **top, unsigned int num);
void _push(stack_t **top, unsigned int data);
void _pop(stack_t **top, unsigned int line_number);
void _pall(stack_t **top, unsigned int num);
void free_stack(stack_t **top);
void _pint(stack_t **top, unsigned int num);
void _swap(stack_t **top, unsigned int num);
void _mul(stack_t **top, unsigned int num);
void _add(stack_t **top, unsigned int num);
void _sub(stack_t **top, unsigned int num);
void _div(stack_t **top, unsigned int num);
void _mod(stack_t **top, unsigned int num);
void _pchar(stack_t **top, unsigned int num);
void _pstr(stack_t **top, unsigned int num);
#endif
