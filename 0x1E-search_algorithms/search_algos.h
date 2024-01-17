#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - The singly linked list
 *
 * @n: An integer
 * @index: The index of the node in the list
 * @next: A Pointer to the next node
 *
 * Description: A singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
		int n;
		size_t index;
		struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - A singly linked list with an express lane
 *
 * @n: An integer
 * @index: The index of the node in the list
 * @next: A pointer to the next node
 * @express: A pointer to the next node in the express lane
 *
 * Description: The singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
				int n;
				size_t index;
				struct skiplist_s *next;
				struct skiplist_s *express;
} skiplist_t;

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_ALGOS_H */