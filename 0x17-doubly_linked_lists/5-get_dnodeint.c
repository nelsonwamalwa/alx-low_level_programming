#include "lists.h"

/**
 * get_dnodeint_at_index - This returns the node at a certain index
 * @head: The first node in a linked list
 * @index: The index of the node to return
 *  Return: The pointer to the node we're looking 
 * for or NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *tempnode = head;

	while (tempnode && i < index)
	{
		tempnode = tempnode->next;
		i++;
	}
	return (tempnode ? tempnode : NULL);
}
