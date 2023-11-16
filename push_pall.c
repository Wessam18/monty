#include "monty.h"
/**
 * push_element - function to insert elements into stack
 * @head: head of linked list.
 * @value: value which need to insert.
*/
void push_element(stack_t **head, unsigned int value)
{
stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}

/**
 * print_all - function to print all elements of stack.
 * @head: head of the linked list.
 * @num_line: line to interpreted by monty
*/
void print_all(stack_t **head, __attribute__((unused))unsigned int num_line)
{
stack_t *temp = *head;

	while (temp != *head)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
