#ifndef MONT_H
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
    void (*f)(stack_t **head, unsigned int num_line);
} instruction_t;

void push_element(stack_t **head, unsigned int value);
void print_all(stack_t **head, unsigned int num_line);

void print_int(stack_t **head, unsigned int num_line);
void remove_element(stack_t **head, unsigned int num_line);

void swap_nodes(stack_t **head, unsigned int num_line);
void add_elements(stack_t **head, unsigned int num_line);

void free_nodes(stack_t **head);
void nop(stack_t **head, unsigned int num_line);

void execute_monty(char *line, unsigned int num_line, stack_t **head);

#endif
