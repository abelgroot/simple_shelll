#include "main.h"

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to write.
 *
 * Return: The character written or -1 on error.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
