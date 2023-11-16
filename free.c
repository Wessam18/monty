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
