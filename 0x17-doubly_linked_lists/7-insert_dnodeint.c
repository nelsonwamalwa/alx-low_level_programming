#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - this inserts a new node
 * @head: a pointer to  first node in the list
 * @idx: the index where the new node is added
 * @n: a data to insert in the new node
 * Return: A pointer to new node or NULL
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	dlistint_t *newnode;
	dlistint_t *tempnode = *head;

	newnode = malloc(sizeof(dlistint_t));
	if (!newnode || !head)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (i = 0; tempnode && i < idx; i++)
	{
		if (i == idx - 1)
		{
			newnode->next = tempnode->next;
			tempnode->next = newnode;
			return (newnode);
		}
		else
		{
			tempnode = tempnode->next;
		}
	}
	return (NULL);
}