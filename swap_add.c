#include "monty.h"
/**
 * swap_nodes - function to swap nodes.
 * @head: head of the stack
 * @num_line: number of args in the line
*/
void swap_nodes(stack_t **head, unsigned int num_line)
{
stack_t *first = *head;
stack_t *second = (*head)->next;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	first->next = second->next;
	second->prev = first->prev;

	if (first->next != NULL)
		first->next->prev = first;

	first->prev = second;
	second->next = first;
	*head = second;
}

/**
 * add_elements - function that add the first 2 elements of the stack
 * @head: head of the stack
 * @num_line: number of the args in the line
*/
void add_elements(stack_t **head, unsigned int num_line)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "Error: L%d: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	remove_element(head, num_line);
}
