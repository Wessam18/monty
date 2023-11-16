#include "monty.h"
/**
 * swap_nodes - function to swap nodes.
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void swap_nodes(stack_t **stack, unsigned int line_number)
{
stack_t *first = *stack;
stack_t *second = (*stack)->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	second->prev = first->prev;

	if (first->next != NULL)
		first->next->prev = first;

	first->prev = second;
	second->next = first;
	*stack = second;
}

/**
 * add_elements - function that add the first 2 elements of the stack
 * @stack: head of the stack
 * @line_number: number of the args in the line
*/
void add_elements(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	remove_element(stack, line_number);
}
