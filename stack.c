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

	/* travers the stack to the last node */
	while (head->next)
	{	/* print the node at given positive index */
		if (index == ++j)
		{
			printf("%d\n", head->n);
			return (1);
		}
		head = head->next;
	}

	/* travers the stack to the first node */
	j = 0;
	while (head)
	{	/* if an negative index is given, print the node at this position */
		/* instead print all nodes */
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
		safe_exit(head, EXIT_FAILURE);
	}

	new->next = NULL;
	new->n = n;

	/* insert the new node at end */
	if (current)
	{
		/* look for the last node */
		while (current->next)
			current = current->next;

		current->next = new;
		new->prev = current;
	}
	else
	{	/* it is the fist node */
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
	stack_t *last;

	if (head == NULL || *head == NULL)
		return (-1);

	/* get the last node */
	last = stack_get_top(*head);

	/* remove the last node */
	if (last->prev)
		last->prev->next = NULL;
	else
		*head = NULL;
	free(last);

	return (1);
}


/**
 * stack_free - free the memory of the stack_t list.
 * @head: pointer to the head of the double linked list.
 *
 * Return: nothing.
 */
void stack_free(stack_t *head)
{
	if (head)
	{
		while (head->next)
		{
			/* free each prev node */
			head = head->next;
			free(head->prev);
		}

		free(head);
	}
}


/**
 * stack_get_top - Prints all the elements of a stack_t list.
 * @head: pointer to the head of the double linked list.
 * Return: last nodes
 */
stack_t *stack_get_top(stack_t *head)
{
	if (head == NULL)
		return (NULL);

	while (head->next)
		head = head->next;

	return (head);
}
