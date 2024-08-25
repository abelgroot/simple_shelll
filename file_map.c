#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * initialize_file_map - Initializes the file descriptor mapping.
 */
void initialize_file_map(void)
{
	int i;

	for (i = 0; i < MAX_FILES; i++)
	{
		file_map[i].stream = NULL;
		file_map[i].fd = -1;
	}
}

/**
 * add_file_mapping - Adds a mapping from FILE * to a file descriptor.
 * @stream: The FILE * stream.
 * @fd: The file descriptor to associate with the stream.
 *
 * Return: 0 on success, -1 on failure.
 */
int add_file_mapping(FILE *stream, int fd)
{
	int i;

	for (i = 0; i < MAX_FILES; i++)
	{
		if (file_map[i].stream == NULL)
		{
			file_map[i].stream = stream;
			file_map[i].fd = fd;
			return (0);
		}
	}
	return (-1);  /* No space available */
}

/**
 * get_fd_from_stream - Retrieves the file descriptor for
 * a given FILE * stream.
 * @stream: The FILE * stream to look up.
 *
 * Return: The file descriptor associated with the stream, or -1 if not found.
 */
int get_fd_from_stream(FILE *stream)
{
	int i;

	printf("we reached here");
	for (i = 0; i < MAX_FILES; i++)
	{
		if (file_map[i].stream == stream)
		{
			return (file_map[i].fd);
		}
	}
	return (-1);  /* Stream not found */
}
