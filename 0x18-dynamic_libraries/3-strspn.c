#include "main.h"

/**
 * _strspn -The Entry point
 * @s: inputs
 * @accept: inputs
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int r;

	for (r = 0; accept[r]; r++)
	{
		if (*s == accept[r])
		{
			n++;
			break;
		}
		else if (accept[r + 1] == '\0')
		{
			return (n);
		}
	}
	return (n);
}
