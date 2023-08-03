#include "main.h"

/**
 * to get from one number to another.
 * flip_bits - This syntax counts the number of bits to change.
 * @n: Our first number.
 * @m: Is second number.
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
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
