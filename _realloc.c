#include "main.h"

/**
 * _realloc - Reallocates memory for a string.
 * @str: The original string to reallocate.
 *
 * Return: A pointer to the new memory block, or NULL on failure.
 *
 * This function doubles the size of the given string's memory block.
 * If the original string is NULL or empty, it allocates a new block of
 * memory with an initial size.
 */
void *_realloc(char *str)
{
	size_t old_size = 0, new_size, i;
	void *new_str, *old_str;

	if (str == NULL || str[0] == '\0')
	{
		new_size = BUFFER_SIZE;
		new_str = malloc(new_size);
		if (new_str == NULL)
			return (NULL);
		return (new_str);
	}

	for (i = 0; str[i] != '\0'; i++)
		old_size++;

	new_size = old_size * 2;

	/* Allocate the new memory block */
	new_str = malloc(new_size);
	if (new_str == NULL)
		return (NULL);

	/* Copy the contents of the original memory block to the new memory block */
	old_str = str;
	for (i = 0; i < old_size && i < new_size; i++)
		((char *)new_str)[i] = ((char *)old_str)[i];

	free(old_str);
	return (new_str);
}
