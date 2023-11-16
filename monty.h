#ifndef MONTY_H
#define MONTY_H

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

void push_element(stack_t **stack, unsigned int value);
void p_all(stack_t **stack, unsigned int line_number);

void print_int(stack_t **stack, unsigned int line_number);
void remove_element(stack_t **stack, unsigned int line_number);

void swap_nodes(stack_t **stack, unsigned int line_number);

void add_elements(stack_t **stack, unsigned int line_number);
void sub_elements(stack_t **stack, unsigned int line_number);
void div_elements(stack_t **stack, unsigned int line_number);
void mul_elements(stack_t **stack, unsigned int line_number);

void free_nodes(stack_t **stack);
void nop(stack_t **stack, unsigned int line_number);


void execute_monty(char *line, unsigned int line_number, stack_t **stack);

#endif
