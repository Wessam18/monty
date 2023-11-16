#include "monty.h"
/**
 * execute_monty - function to execute monty script on the stack.
 * @line: line to be get from user
 * @line_number: argument number of the line
 * @stack: head of the stack
*/
void execute_monty(char *line, unsigned int line_number, stack_t **stack)
{
int i;
char *op = strtok(line, " \t\n");
instruction_t monty[] = {
	{"push", push_element}, {"pall", p_all}, {"pint", print_int},
	{"pop", remove_element}, {"swap", swap_nodes}, {"add", add_elements},
	{"nop", nop}, {NULL, NULL}
};

	if (op == NULL)
		return;

	for (i = 0; monty[i].opcode != NULL; i++)
	{
		if (strcmp(op, monty[i].opcode) == 0)
		{
			monty[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "Error: L%d: Unknown opcode %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
