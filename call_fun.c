#include "monty.h"
/**
 * execute_monty - function to execute monty script on the stack.
 * @line: line to be get from user
 * @num_line: argument number of the line
 * @head: head of the stack
*/
void execute_monty(char *line, unsigned int num_line, stack_t **head)
{
int i;
char *op = strtok(line, " \t\n");
instruction_t monty[] = {
	{"push", push_element}, {"pall", print_all}, {"pint", print_int},
	{"pop", remove_element}, {"swap", swap_nodes}, {"add", add_elements},
	{"nop", nop}, {NULL, NULL}
};

	if (op == NULL)
		return;

	for (i = 0; monty[i].opcode != NULL; i++)
	{
		if (strcmp(op, monty[i].opcode) == 0)
		{
			monty[i].f(head, num_line);
			return;
		}
	}

	fprintf(stderr, "Error: L%d: Unknown opcode %s\n", num_line, op);
	exit(EXIT_FAILURE);
}
