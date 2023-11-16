#include "monty.h"
/**
 * free_nodes - fuction to free the stack
 * @head: head of the stack
*/
void free_nodes(stack_t **head)
{
stack_t *temp;

	while (temp != NULL)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
	*head = NULL;
}

/**
 * nop - function that not print anything
 * @head: head of the stack.
 * @num_line: number of args in the line
*/
void nop(stack_t **head, unsigned int num_line)
{
	(void)head;
	(void)num_line;
}
