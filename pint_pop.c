#include "monty.h"
/**
 * print_int - function to convert arg. to int and print all.
 * @head: head of the stack.
 * @num_line: number of arguments in line
*/
void print_int(stack_t **head, unsigned int num_line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "Error: L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * remove_element - function to pop elements from stack
 * @head: head of the stack
 * @num_line: number of args in line.
*/
void remove_element(stack_t **head, unsigned int num_line)
{
stack_t *top;

	if (*head == NULL)
	{
		fprintf(stderr, "Error: L%d: can't pop stack\n", num_line);
		exit(EXIT_FAILURE);
	}


	top = *head;
	*head = top->next;

	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(top);
}
