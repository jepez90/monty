#include "monty.h"


/**
 * open_file - function that open a file
 * @file: pointer to a doubly FILE object to store the open file
 * @argv: array of arguments pased to the program as strings
 * Return: nothing
 */
void open_file(FILE **file, char **argv)
{
	/* open the file */
	*file = fopen(argv[1], "r");
	if (*file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}



/**
 * read_file - function that read a line of a file
 * @file: pointer to a doubly FILE object to store the open file
 * Return: nothing
 */
int read_file(FILE *file)
{
	ssize_t bytes_read = 0;
	size_t bytes_to_read = BUFFER_SIZE;
	char buffer[BUFFER_SIZE] = {0}, *token = NULL;
	char *buffer_ptr = buffer;

	data.opcode[0] = '\0';
	data.arg[0] = '\0';
	/* Read one line of the file */
	bytes_read = getline(&buffer_ptr, &bytes_to_read, file);
	if (bytes_read > 0)
	{
		/* if the read was valid */
		/* obtain the first tow tokens */
		token = strtok(buffer, " \t\n");
		if (token)
		{
			strcpy(data.opcode, token);

			token = strtok(NULL, " \t\n");
			if (token)
				strcpy(data.arg, token);
			else
				data.arg[0] = '\0';
		}
		else
		{	/* if the first token is NULL, optcode = "" */
			data.opcode[0] = '\0';
			return (0);
		}
	}
	return (bytes_read);
}
