#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct Rvar_s - variables -args, file, line fcontent
 * @ag: value
 * @file: pointer to monty file
 * @fcontent: line fcontent
 * @fque: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct Rvar_s
{
	char *ag;
	FILE *file;
	char *fcontent;
	int fque;
}  fvar_t;

extern fvar_t fuse;

int Rexec(char *, stack_t **, unsigned int, FILE *);
void free_rstack(stack_t *);

/* basic operations */
void s_push(stack_t **, unsigned int);
void s_pall(stack_t **, unsigned int);
void s_pint(stack_t **, unsigned int);
void s_pop(stack_t **, unsigned int);
void s_swap(stack_t **, unsigned int);

/* maths operations */
void s_add(stack_t **, unsigned int);
void s_sub(stack_t **, unsigned int);
void s_div(stack_t **, unsigned int);
void s_mul(stack_t **, unsigned int);
void s_mod(stack_t **, unsigned int);

/* for other operations*/
void s_nop(stack_t **, unsigned int);
void s_pchar(stack_t **, unsigned int);
void s_pstr(stack_t **, unsigned int);
void s_rotl(stack_t **, unsigned int);
void s_rotr(stack_t **, __attribute__((unused)) unsigned int);

/* for nodes*/
void faddnode(stack_t **, int);
void s_stack(stack_t **, unsigned int);
void s_queue(stack_t **, unsigned int);
void faddqueue(stack_t **, int);

#endif /* MONTY_H */
