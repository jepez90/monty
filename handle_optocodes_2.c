#include "monty.h"


/**
 * handle_math - function that add the 2 last numbers in the stack and
 * store it in the second top element and then remove the last
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_math(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;

	/* get the last node */
	last = stack_get_top(*stack);
	if (last == NULL || last->prev == NULL)
	{	/* if doesn't exist the last node or its prev */
		dprintf(STDERR_FILENO, "L%u: can't %s, stack too short\n",
													line_number, data.opcode);
		exit(EXIT_FAILURE);
	}
	/* make the operation with the numbers */
	if (data.opcode[0] == 'a') /* add */
		last->prev->n += last->n;
	else if (data.opcode[0] == 's')/* sub */
		last->prev->n -= last->n;
	else if (data.opcode[0] == 'd')/* div */
	{
		if (last->n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
			last->prev->n /= last->n;
	}
	else if (data.opcode[0] == 'm' && data.opcode[1] == 'u')/* mul */
		last->prev->n *= last->n;
	else if (data.opcode[0] == 'm' && data.opcode[1] == 'o')/* mod */
	{
		if (last->n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		else
			last->prev->n %= last->n;
	}
	/* remove the last node */
	last->prev->next = NULL;
	free(last);
}
