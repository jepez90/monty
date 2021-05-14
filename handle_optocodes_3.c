#include "monty.h"


/**
 * handle_stack - change the vehavior of the list to LIFO
 * @UNUSED: pointer to a doubly linked list representation of a stack
 * @UNUSED: int that represents the line read of the file
 * Return: nothing
 */
void handle_stack(stack_t **stack UNUSED, uns line_number UNUSED)
{
	/* set the vehavior */
	data.vehavior = STACK;
}


/**
 * handle_queue - change the vehavior of the list to FIFO
 * @UNUSED: pointer to a doubly linked list representation of a stack
 * @UNUSED: int that represents the line read of the file
 * Return: nothing
 */
void handle_queue(stack_t **stack UNUSED, uns line_number UNUSED)
{
	/* set the vehavior */
	data.vehavior = QUEUE;
}
