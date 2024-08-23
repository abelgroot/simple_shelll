#include "main.h"
void *_realloc(char *str)
{
    size_t old_size = 0, new_size, i;
    void *new_str, *old_str;

    if (str == NULL || str[0] == '\0')
    {
        new_size = 8;
        new_str = malloc(new_size);
        if (new_str == NULL)
            return NULL;
        return new_str;
    }
    
    for (i = 0; str[i] != '\0'; i++)
	    old_size++;
	    
    new_size = old_size * 2;
    /*Allocate the new memory block*/
    new_str = malloc(new_size);
    if (new_str == NULL)
        return NULL;

    /*Copy the contents of the original memory block to the new memory block*/
    old_str = str;
    for (i = 0; i < old_size && i < new_size; i++)
        ((char *)new_str)[i] = ((char *)old_str)[i];

    free(old_str);
    return new_str;
}