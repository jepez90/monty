#include "monty.h"

data_t data = {{'\0'}, {'\0'}, STACK};

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

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	open_file(&file, argv);

	while (++line_number)
	{
		bytes_read = read_file(file);
		if (bytes_read == EOF)
			break;
		if (bytes_read != 0)
			execute(&stack, line_number);
	}
	fclose(file);
	stack_free(stack);
	return (EXIT_SUCCESS);
}


/**
 * execute - find the function that handle the opcode and execute it
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void execute(stack_t **stack, uns line_number)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pop", handle_pop},
		{"swap", handle_swap},
		{"add", handle_math},
		{"sub", handle_math},
		{"div", handle_math},
		{"mul", handle_math},
		{"mod", handle_math},
		{"pchar", handle_pchar},
		{"pstr", handle_pstr},
		{"rotl", handle_rotl},
		{"rotr", handle_rotr},
		{"queue", handle_queue},
		{"stack", handle_stack},
		{NULL, NULL}
	};
	for (; instructions[i].opcode != NULL; i++)
		if (strcmp(instructions[i].opcode, data.opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	if (strcmp("nop", data.opcode) == 0 || data.opcode[0] == '#')
		return;

	dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
												line_number, data.opcode);
	exit(EXIT_FAILURE);
}
