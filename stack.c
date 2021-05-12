#include "monty.h"


/**
 * stack_print - Prints all the elements of a stack_t list.
 * @head: pointer to the head of the double linked list.
 * @index: number that represent the element to be printed,
 * if 0, print all list, if <0, print last element and if >0 print firt element
 * Return: number of printed nodes
 */
size_t stack_print(const stack_t *head, int index)
{
	int i = 0, j = 0;

	if (head == NULL)
		return (i);

	while (head->next)
	{
		if (index > 0 && index == ++j)
		{
			printf("%d\n", head->n);
			return (1);
		}
		head = head->next;
	}

	j = 0;
	while (head)
	{
		if (index < 0)
		{
			if (index == --j)
			{
				printf("%d\n", head->n);
				return (1);
			}
		}
		else
			printf("%d\n", head->n);
		head = head->prev;
		i++;
	}
	return (i);
}

/**
 * stack_push - adds a new node at the end of a stack_t list.
 * @head: pointer to the head of the double linked list.
 * @n: number to be stored in the new node.
 *
 * Return: new node or NULL.
 */
stack_t *stack_push(stack_t **head, const int n)
{
	stack_t *new, *current = NULL;

	if (head == NULL)
		return (NULL);

	current = *head;

	/* create the new node */
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = n;

	/* insert the new node */
	if (current)
	{
		/* look for the last node */
		while (current->next)
			current = current->next;

		current->next = new;
		new->prev = current;
	}
	else
	{
		new->prev = NULL;
		*head = new;
	}
	return (new);
}

/**
 * stack_pop - remove at end of list.
 * @head: pointer to the head of the double linked list.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int stack_pop(stack_t **head)
{
	stack_t *current = *head;

	if (head == NULL || *head == NULL)
		return (-1);

	while (current->next)
		current = current->next;

	if (current)
	{
		if (current->prev)
			current->prev->next = NULL;
		else
			*head = NULL;

		free(current);
		return (1);
	}

	return (-1);
}
