#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * add_dnodeint_end - This adds a node the end
 * @head: points to the first element in list
 * @n: data to insert in the new element
 * Return: pointer to the new node, or NULL if it fails
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newnode;
	dlistint_t *tempnode = *head;

	newnode = malloc(sizeof(dlistint_t));
	if (!newnode)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	while (tempnode->next)
	{
		tempnode = tempnode->next;
	}
	tempnode->next = newnode;
	return (newnode);
}