#include "lists.h"
#include <stddef.h>
/**
 *  dlistint_len -This returns the number of the elements
 *  @h: A linked list of type a listint_t to traverse
 *  Return: Given number of the nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t number = 0;

	while (h)
	{
		number++;
		h = h->next;
	}
	return (number);
}
