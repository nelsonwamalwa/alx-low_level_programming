#include "main.h"

/**
 * @index: index of the bit to clear
 * @n: pointer to the number to change
 * clear_bit - This sets the value of a given bit to 0
 *
 * Return: Return 1 is for success whilst -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
