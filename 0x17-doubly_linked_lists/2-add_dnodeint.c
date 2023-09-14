#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *  add_dnodeint - This adds a new node at the begining
 *  @head: A pointer for the first node in list
 *  @n: The data to insert in that new node
 *  Return: The pointer to the new node,
 * and or NULL if it fails
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;

	return (newnode);
}