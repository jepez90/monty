#include "monty.h"
/**
 * main - entry point of the program
 * @argc: number of arguments pased to the program
 * @argv: array of arguments pased to the program as strings
 * Return: 0 on succes, 1 on error
 */
int main(int argc, char **argv)
{
	int bytes_read = 0, arg;
	stack_t stack;
	FILE *file = NULL;
	char optcode[BUFFER_SIZE] = {0};

	if (argc != 2)
	{
		dprintf(STDERR_FILENO,"USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	open_file(&file, argv);

	bytes_read = read_file(file, optcode, &arg);
	while (bytes_read != EOF)
	{
		bytes_read = read_file(file, optcode, &arg);
	}
	fclose(file);
}


