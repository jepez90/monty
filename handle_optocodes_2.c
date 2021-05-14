#include "monty.h"


/**
 * handle_math - function that add the 2 last numbers in the stack and
 * store it in the second top element and then remove the last
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_math(stack_t **stack, uns line_number)
{
	stack_t *last = NULL;
	char letter0;

	/* get the last node */
	last = stack_get_top(*stack);

	/* check for the stack's long */
	if (last == NULL || last->prev == NULL)
	{
		dprintf(STDERR_FILENO, SHORT_STACK_ERR, line_number, data.opcode);
		exit(EXIT_FAILURE);
	}

	/* letter0 = a:add, s:sub, d:div, m:mul, o:mod */
	letter0 = data.opcode[0];
	if (data.opcode[0] == 'm' && data.opcode[1] == 'o')
		letter0 = 'o';

	/*check for division by zero error*/
	if ((letter0 == 'd' || letter0 == 'o') && last->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* make the operation with the numbers */
	if (letter0 == 'a') /* add */
		last->prev->n += last->n;
	else if (letter0 == 's')/* sub */
		last->prev->n -= last->n;
	else if (letter0 == 'd')/* div */
		last->prev->n /= last->n;
	else if (letter0 == 'm')/* mul */
		last->prev->n *= last->n;
	else if (letter0 == 'o')/* mod */
		last->prev->n %= last->n;

	/* remove the last node */
	last->prev->next = NULL;
	free(last);
}


/**
 * handle_pchar - function that print a int as char
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_pchar(stack_t **stack, uns line_number)
{
	stack_t *last = NULL;

	/* get the last node */
	last = stack_get_top(*stack);

	if (last == NULL)
	{
		/* if doesn't exist the last  */
		dprintf(STDERR_FILENO, EMPTY_STACK_ERR, line_number, data.opcode);
		exit(EXIT_FAILURE);
	}
	/* check if n is a valid char */
	if (last->n < 1 || last->n > 126)
	{
		dprintf(STDERR_FILENO, OUT_OF_RANGE_ERR, line_number, data.opcode);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", last->n);
}


/**
 * handle_pstr - function that prints all stack numbers as chars
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_pstr(stack_t **stack, uns line_number)
{
	stack_t *node;
	char buffer[BUFFER_SIZE] = {'\0'};
	int i = 0;

	if (stack == NULL)
		printf("\n");

	/* get the last node */
	node = stack_get_top(*stack);

	/* iterate the list since the last node*/
	while (node)
	{
		if (node->n <= 32 || node->n > 126)
			break;
		buffer[i++] = node->n;
		node = node->prev;
	}
	buffer[i++] = '\n';
	printf("%s", buffer);
	line_number++;
}


/**
 * handle_rotl - function that rotate the stack to up
 * @stack: pointer to a doubly linked list representation of a stack
 * @UNUSED: int that represents the line read of the file
 * Return: nothing
 */
void handle_rotl(stack_t **stack, uns line_number UNUSED)
{
	stack_t *last = NULL;

	/* get the last node */
	last = stack_get_top(*stack);

	/* check if the stack is empty or its length is 1 */
	if (last == NULL || last == *stack)
		return;

	/* insert the last node at begin of the stack */
	last->next = (*stack);
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;

}


/**
 * handle_rotr - function that rotate the stack to down
 * @stack: pointer to a doubly linked list representation of a stack
 * @UNUSED: int that represents the line read of the file
 * Return: nothing
 */
void handle_rotr(stack_t **stack, uns line_number UNUSED)
{
	stack_t *last = NULL;

	/* get the last node */
	last = stack_get_top(*stack);

	/* check if the stack is empty or its length is 1 */
	if (last == NULL || last == *stack)
		return;

	/* insert the first node at end of the stack */
	last->next = (*stack);
	(*stack)->prev = last;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	last->next->next = NULL;
}
