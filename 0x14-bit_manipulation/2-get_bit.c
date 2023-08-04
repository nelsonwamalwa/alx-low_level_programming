#include "main.h"

/**
 *get_bit -This returns the value or series of a bit at an index in a decimal number
 * @n:The number to search
 * @index:Gets the  index of the bit
 *
 * Return:The  value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
