#include "lists.h"

/**
 * free_dlistint - This frees dlistint_t list.
 * @head: A pointer to a head of the list
 * Return: Is nothing
 **/
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
	return;

	while (head->next)
	{
	head = head->next;
	free(head->prev);
	}
	free(head);
}