#include "main.h"

/**
 * flip_bits -This loop  counts the number of bits to change
 * to get from one number to another
 * @n:The  first number
 * @m:The  second number
 *
 * Return: number of bits to change
 */

{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
