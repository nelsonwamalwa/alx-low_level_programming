#include "main.h"

/**
 * _isalpha - checker  for alpha
 * @c: to be checked
 * Return: 1 for alpha and 0 for nothing else.
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 98) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
