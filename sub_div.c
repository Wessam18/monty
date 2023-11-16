#include "monty.h"
/**
 * sub_elements - function to sub elements of the stack
 * @stack: head of the stack
 * @line_number: number of args
 *
*/
void sub_elements(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	remove_element(stack, line_number);
}

/**
 * div_elements - function to divide the elements of the stack
 * @stack: head of the stack
 * @line_number: number of args
*/
void div_elements(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	remove_element(stack, line_number);
}
