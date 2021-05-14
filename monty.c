#include "monty.h"

/* inicialize the global variable data */
data_t data = {{'\0'}, {'\0'}, STACK, NULL};

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

	/* check the arguments */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* try to open the file */
	open_file(&(data.file), argv);

	/* infinit loop, to read and execute each file line */
	while (++line_number)
	{
		/* read one line and break the loop when end of file */
		bytes_read = read_file(data.file);
		if (bytes_read == EOF)
			break;

		/* search an execute the opt function if is an valid optcode */
		if (bytes_read != 0)
			execute(&stack, line_number);
	}

	safe_exit(&stack, EXIT_SUCCESS);
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
	static instruction_t instructions[] = {
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

	/* if is the optcode is nop or #, it doesn’t do anything.*/
	if (strcmp("nop", data.opcode) == 0 || data.opcode[0] == '#')
		return;

	/* check for the opcode in the array */
	for (; instructions[i].opcode != NULL; i++)
		if (strcmp(instructions[i].opcode, data.opcode) == 0)
		{
			/* execute the function when find it */
			instructions[i].f(stack, line_number);
			return;
		}

	/* if the give optcode is not in the list */
	dprintf(STDERR_FILENO, NO_OPTCODE_ERR, line_number, data.opcode);
	safe_exit(stack, EXIT_FAILURE);

}


/**
 * safe_exit - exit the program when free and close all
 * @stack: pointer to a doubly linked list representation of a stack
 * @status: exit status
 * Return: nothing
 */
void safe_exit(stack_t **stack, int status)
{
	if (data.file)
		fclose(data.file);

	stack_free(*stack);
	exit(status);
}
