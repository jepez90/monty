#include "monty.h"

void open_file(FILE **file, char **argv)
{
	*file = fopen(argv[1], "r");
	if (*file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
}

int read_file(FILE *file, char *optcode, int *arg)
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
		token = strtok(buffer, " \tn");
		if (token)
		{
			copy_buffer(token, optcode);

			token = strtok(NULL, " \tn");
			if (token)
			{
				*arg = atoi(token);
				token = strtok(NULL, " \t\n");
				if (token)
				{
					dprintf(STDERR_FILENO, "Error in lengt of optcode");
					exit (EXIT_FAILURE);
				}

			}
			else
				arg = 0;
		}
		else
		{
			exit (EXIT_FAILURE);
		}

	}
	return bytes_read;
}
