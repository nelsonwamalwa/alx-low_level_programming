#include <unistd.h>

/**
 * _putchar -This  writes the character c to stdout
 * @c: character to print.
 * Return: On Success 1
 * on error -1 is returned and error number is set appropriately
 */

int _putchar(char c)
{
		return (write(1, &c, 1));
}
