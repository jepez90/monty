#include "monty.h"

char optcode_arg[BUFFER_SIZE] = {'\0'};

/**
 * main - entry point of the program
 * @argc: number of arguments pased to the program
 * @argv: array of arguments pased to the program as strings
 * Return: 0 on succes, 1 on error
 */
int main(int argc, char **argv)
{
	int bytes_read = 0;
	uns line_number = 0;
	stack_t *stack = NULL;
	FILE *file = NULL;
	char optcode[BUFFER_SIZE] = {0};

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	open_file(&file, argv);

	while (++line_number)
	{
		bytes_read = read_file(file, optcode);
		if (bytes_read == EOF)
			break;
		if (bytes_read != 0)
			execute(&stack, optcode, line_number);
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}


/**
 * execute - find the function that handle the optcode and execute it
 * @stack: pointer to a doubly linked list representation of a stack
 * @optcode: pointer to string that represent an optcode
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void execute(stack_t **stack, char *optcode, uns line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push_optcode},
		{"pall", pall_optcode},
		{"pint", pint_optcode},
		{"pop", pop_optcode},
		{NULL, NULL}
	};
	for (; instructions[i].opcode != NULL; i++)
		if (strcmp(instructions[i].opcode, optcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
														line_number, optcode);
	exit(EXIT_FAILURE);
}
