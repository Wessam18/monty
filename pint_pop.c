#include "monty.h"
/**
 * p_int - function to convert arg. to int and print all.
 * @stack: head of the stack.
 * @line_number: number of arguments in line
*/
void p_int(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * remove_el - function to pop elements from stack
 * @stack: head of the stack
 * @line_number: number of args in line.
*/
void remove_el(stack_t **stack, unsigned int line_number)
{
stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	top = *stack;
	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}
