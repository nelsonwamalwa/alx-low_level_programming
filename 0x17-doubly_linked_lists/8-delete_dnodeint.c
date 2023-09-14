#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - This deletes a node
 * @head: A pointer to the first element in the list
 * @index: the index of the node to delete
 * Return: 1 for Success or -1 for fail
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tempnode = *head;
	dlistint_t *currentnode = NULL;
	unsigned int i = 0;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		*head = (*head)->next;
		free(tempnode);
		return (1);
	}
	while (i < index - 1)
	{
		if (!tempnode || !(tempnode->next))
		{
			return (-1);
		}
		tempnode = tempnode->next;
		i++;
	}
	currentnode = tempnode->next;
	tempnode->next = currentnode->next;
	free(currentnode);
	return (1);
}