#include "monty.h"
/**
 * pchar_el - function print char at top of stack
 * @stack: head of the stack
 * @line_number: number of args in the line
*/
void pchar_el(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);

	remove_el(stack, line_number);
}
