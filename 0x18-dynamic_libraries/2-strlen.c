#include "main.h"

/**
 * _strlen -This  returns the length of a string
 * @s: thE string
 * Return:The length
 */

int _strlen(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}
