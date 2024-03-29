#ifndef _HEADER_H
#define _HEADER_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void openfile(char *file_name);
int parseline(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_function(char *, char *, int, int);

/*Stack operations*/
stack_t *cr_node(int n);
void freenodes(void);
void printst(stack_t **, unsigned int);
void addtostack(stack_t **, unsigned int);
void addnodequeue(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);

void printthetop(stack_t **, unsigned int);
void poptop(stack_t **, unsigned int);
void nothing_op(stack_t **, unsigned int);
void swapnodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void addnodes(stack_t **, unsigned int);
void subnodes(stack_t **, unsigned int);
void divnodes(stack_t **, unsigned int);
void multiply_nd(stack_t **, unsigned int);
void modulus_nd(stack_t **, unsigned int);

/*String operations*/
void print_chr(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotm(stack_t **, unsigned int);

/*Error hanlding*/
void err_err(int error_code, ...);
void more_err_c(int err_c, ...);
void string_err(int err_c, ...);
void rotp(stack_t **, unsigned int);

#endif
