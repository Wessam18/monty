#include "monty.h"
/**
 * main - main function to work on stack as monty language.
 * @argc: number of arguments.
 * @argv: arguments to be read.
 * Return: as need.
*/
int main(int argc, char *argv[])
{
char *name, *lline = NULL;
FILE *fd;
size_t n = 0;
ssize_t read_file;
unsigned int num_line = 0;
stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Error: please provide a file as an argument.\n");
		exit(EXIT_FAILURE);
	}
	name = argv[1];
	fd = fopen(name, "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: cannot open file %s.\n", name);
		exit(EXIT_FAILURE);
	}

	while ((read_file = getline(&lline, &n, fd)) != -1)
	{
		num_line++;
		execute_monty(lline, num_line, &head);
	}
	fclose(fd);
	free(lline);
	free_nodes(&head);
	return (EXIT_SUCCESS);
}
