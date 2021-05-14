#include "monty.h"


/**
 * queue_enqueue - adds a new node in the front of a stack_t list.
 * @head: pointer to the head of the double linked list.
 * @n: number to be stored in the new node.
 *
 * Return: new node or NULL.
 */
stack_t *queue_enqueue(stack_t **head, const int n)
{
	stack_t *new, *first = NULL;

	if (head == NULL)
		return (NULL);

	/* create the new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = n;

	/* insert the new node */
	first = *head;

	if (first)
	{
		new->next = first;
		first->prev = new;
	}

	*head = new;

	return (new);
}
