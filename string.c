#include "monty.h"


/**
 * copy_buffer - copy the string since origin to dest
 * @origin: pointer to the source string
 * @dest: pointer to the destin
 * Return: nothing
 */
void copy_buffer(char *origin, char *dest)
{
	int i = 0;

	if (origin != NULL)
		for (; origin[i]; i++)
			dest[i] = origin[i];

	dest[i] = '\0';

}
