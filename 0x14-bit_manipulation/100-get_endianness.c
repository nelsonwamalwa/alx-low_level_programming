#include "main.h"
/**
 * Return: 0 is for big and 1 for little
 * get_endianness - checks if a machine is little or big endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
