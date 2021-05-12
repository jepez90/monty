#include "monty.h"


/**
 * open_file - function that open a file
 * @file: pointer to a doubly FILE object to store the open file
 * @argv: array of arguments pased to the program as strings
 * Return: nothing
 */
void open_file(FILE **file, char **argv)
{
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
 * @optcode: pointer to string that represent an optcode
 * @line_number: number of the read line
 * Return: nothing
 */
int read_file(FILE *file, char *optcode, uns line_number)
{
	ssize_t bytes_read = 0;
	size_t bytes_to_read = BUFFER_SIZE;
	char buffer[BUFFER_SIZE] = {0}, *token = NULL;
	char *buffer_ptr = buffer;

	/* Read one line of the file */
	bytes_read = getline(&buffer_ptr, &bytes_to_read, file);
	if (bytes_read != -1)
	{
		/* if the read was valid */
		/* tokenize the line */
		token = strtok(buffer, " \t\n");
		if (token)
		{
			copy_buffer(token, optcode);

			token = strtok(NULL, " \t\n");
			copy_buffer(token, optcode_arg);
			if (token)
			{
				token = strtok(NULL, " \t\n");
				if (token)
				{
					dprintf(STDERR_FILENO, "L%dError in lengt of optcode\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
		}
		else
		{
			exit(EXIT_FAILURE);
		}

	}
	return (bytes_read);
}

