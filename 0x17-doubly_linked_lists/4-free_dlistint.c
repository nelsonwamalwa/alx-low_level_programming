#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - this frees a linked list
 * @head: the listint_t list to be freed
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tempnode;

	while (head)
	{
		tempnode = head->next;
		free(head);
		head = tempnode;
	}
}
