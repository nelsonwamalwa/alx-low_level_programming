#include "main.h"

/**
 * create_file - This command  Creates a file.
 * @filename: This represents pointer to the name of the file to create.
 * @text_content: This a pointer to a string to write to the file.
 *
 * Return: The return is --1.if the function fails and
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
