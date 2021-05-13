#include "monty.h"


/**
 * handle_push - function that add a node at en of the stack
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_push(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char test;
	/* check the arg */
	for (i = 0; (test = data.arg[i]); i++)
		if ((test < '0' || test > '9') && test != '+' && test != '-')
		{
			i = 0;
			break;
		}

	if (i == 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* put the number in the stack */
	stack_push(stack, atoi(data.arg));
}


/**
 * handle_pall - function that prints all stack
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_pall(stack_t **stack, unsigned int line_number)
{
	/* print all number in the stack */
	stack_print(*stack, 0);
	/* this line avoid an error for unuser arg line_number */
		line_number++;
}


/**
 * handle_pint - function that print the last node in the stack
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_pint(stack_t **stack, unsigned int line_number)
{
	/* try to print the last node */
	if (stack_print(*stack, -1) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * handle_pop - function that remove the last node in the stack
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_pop(stack_t **stack, unsigned int line_number)
{
	/* try to remove the last node */
	if (stack_pop(stack) == -1)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * handle_swap - function that swap the last 2 numbers in the stack
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *last = NULL;
	int hold;

	/* get the last node */
	last = stack_get_top(*stack);

	if (last == NULL || last->prev == NULL)
	{
		/* if doesn't exist the last node or its prev */
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* swap only the numbers */
	hold = last->n;
	last->n = last->prev->n;
	last->prev->n = hold;
}