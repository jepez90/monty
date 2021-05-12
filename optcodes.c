#include "monty.h"


/**
 * push_optcode - function that handle the optcode push
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void push_optcode(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char test;
	/* check the arg */
	for (i = 0; (test = optcode_arg[i]); i++)
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
	stack_push(stack, atoi(optcode_arg));
}


/**
 * pall_optcode - function that handle the optcode pall
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void pall_optcode(stack_t **stack, unsigned int line_number)
{
	stack_print(*stack, 0);
	if (line_number > 10)
		line_number++;
}


/**
 * pint_optcode - function that handle the optcode pint
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void pint_optcode(stack_t **stack, unsigned int line_number)
{
	if (stack_print(*stack, -1) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * pop_optcode - function that handle the optcode pop
 * @stack: pointer to a doubly linked list representation of a stack
 * @line_number: int that represents the line read of the file
 * Return: nothing
 */
void pop_optcode(stack_t **stack, unsigned int line_number)
{
	if (stack_pop(stack) == -1)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
