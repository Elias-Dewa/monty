#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

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
 * struct global_variable - global variables with functions
 * @file: pointer to the file
 * @buffer: pointer to store
 * @push_arg: to handle opcode
 *
 * Description: carry the files value in the program
 */
typedef struct global_v
{
	FILE *file;
	char *buffer;
	int push_arg;
} global_t;

extern global_t global;
extern int push_arg;

void process_file(char *file_name, stack_t **stack);
char *content_fun(char *content, size_t **stack, unsigned int num_line);
typedef void (*instruction_fun)(stack_t **stack, unsigned int num_line);
instruction_fun op_fun(char *str);
void free_all(stack_t *head);
int isnum(char *str);

void _pall(stack_t **stack, unsigned int num_line);
void _push(stack_t **stack, unsigned int num_line);
void _pint(stack_t **stack, unsigned int num_line);
void _swap(stack_t **stack, unsigned int num_line);
void _nop(stack_t **stack, unsigned int num_line);
void _add(stack_t **stack, unsigned int num_line);
void _sub(stack_t **stack, unsigned int num_line);
void _div(stack_t **stack, unsigned int num_line);
void _mul(stack_t **stack, unsigned int num_line);
void _mod(stack_t **stack, unsigned int num_line);
void _pchar(stack_t **stack, unsigned int num_line);
void _pstr(stack_t **stack, unsigned int num_line);
void _rotl(stack_t **stack, unsigned int num_line);
void _rotr(stack_t **stack, unsigned int num_line);

#endif
