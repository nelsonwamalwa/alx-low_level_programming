/*
 * File: 104-advanced_binary.c task
 * Auth: Wamalwa Nelson
 */

#include "search_algos.h"

/**
  * advanced_binary_recursive - Searching recursively for a value in a sorted
  *                             array of integers using binary search.
  * @array: Pointer to the first element of the [sub]array to search.
  * @left: Starting index of the [sub]array to search.
  * @right: Ending index of the [sub]array to search.
  * @value: Value to search for.
  *
  * Return: The value is not present, -1.
  *         Otherwise, index where the value is located.
  *
  * Description: Printing the [sub]array being searched after each change.
  */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
  * advanced_binary - Searching for a value in a sorted array
  *                   of integers using advanced binary search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for.
  *
  * Return: The value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  * Description: Printing the [sub]array being searched after each change.
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}