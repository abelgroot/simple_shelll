#include "main.h"

/**
 * read_command - Reads a command line from stdin.
 * @line: Pointer to the buffer storing the command.
 * @len: Pointer to the size of the buffer.
 *
 * Return: The number of characters read, or -1 on failure.
 */
ssize_t read_command(char **line, size_t *len)
{
	ssize_t nread;

	nread = getline(line, len, stdin);
	if (nread != -1)
	{
		(*line)[nread - 1] = '\0';  /* Remove newline character */
	}

	return (nread);
}