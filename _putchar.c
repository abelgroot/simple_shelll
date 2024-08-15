#include "main.h"

static char buffer[BUFFER_SIZE];
static int buffer_index;

/**
* _putchar - Writes a character to the buffer.
* @c: The character to write.
*
* Return: On success 1.
*/
int _putchar(char c)
{
	if (buffer_index >= BUFFER_SIZE)
		_flush_buffer();

	buffer[buffer_index++] = c;
	return (1);
}

/**
* _flush_buffer - Flushes the buffer to stdout.
*/
void _flush_buffer(void)
{
	write(1, buffer, buffer_index);
	buffer_index = 0;
}

