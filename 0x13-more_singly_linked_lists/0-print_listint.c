#include "lists.h"

/**
 *  * print_listint - Prints all the elements of a linked list.
 *   * @h: Linked list of type listint_t to be printed.
 *    *
 *     *Return: This code returns a Series of nodes.
*/
size_t print_listint(const listint_t *h)
{
	size_t nod = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;

		nod = nod + 1;
	}

	return (nod);
}
