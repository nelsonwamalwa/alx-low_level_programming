#include "lists.h"

/**
 * sum_dlistint - this calculates the sum
 * @head: the first node in linked list
 *  Return: the resulting sum
 */

int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *tempnode = head;

	while (tempnode)
	{
		total += tempnode->n;
		tempnode = tempnode->next;
	}
	return (total);
}