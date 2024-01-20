#include <stdlib.h>
#include "search_algos.h"

/**
 * free_skiplist - Deallocating singly linked list
 *
 * @list: Pointering a linked list to be freed
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_skiplist(node);
	}
}