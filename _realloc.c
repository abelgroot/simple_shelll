#include "main.h"

/**
 * _realloc - Reallocates a memory block for a string
 * @str: The string to reallocate memory for
 *
 * Return: Pointer to the newly allocated memory, or NULL on failure
 */
void *_realloc(char *str)
{
	size_t old_size = 0, new_size, i;
	void *new_str, *old_str;

	if (str == NULL || str[0] == '\0')
	{
		new_size = 8;
		new_str = malloc(new_size);
		if (new_str == NULL)
			return (NULL);
		return (new_str);
	}

	for (i = 0; str[i] != '\0'; i++)
		old_size++;

	new_size = old_size * 2;

	new_str = malloc(new_size);
	if (new_str == NULL)
		return (NULL);

	old_str = str;
	for (i = 0; i < old_size && i < new_size; i++)
		((char *)new_str)[i] = ((char *)old_str)[i];

	free(old_str);
	return (new_str);
}
