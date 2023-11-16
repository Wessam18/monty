#include "monty.h"
/**
 * mul_elements - function to mul the elements of the stack
 * @stack: the head of the stack
 * @line_number: the number of the args
 * 
*/
void mul_elements(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	remove_element(stack, line_number);
}
