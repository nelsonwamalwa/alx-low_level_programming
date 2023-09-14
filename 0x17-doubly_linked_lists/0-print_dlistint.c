#include "lists.h"
#include <stddef.h>

/**
 * print_dlistint - This prints all the elements
 * @h: One linked list of a type dlistint_t to print
 * Return: Given number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t num = 0;

	while (h)
	{
		printf("%d\n", h->n);
		num++;
		h = h->next;
	}
	return (num);
}