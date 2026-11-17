#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc(old_size)
 * @old_size: size in bytes of the allocated space for ptr
 * @new_size: new size in bytes of the memory block
 *
 * Return: pointer to the new block, ptr if sizes are equal,
 * or NULL on failure or when new_size is 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *old;
	unsigned int i, min;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old = ptr;
	min = old_size;
	if (new_size < old_size)
		min = new_size;

	for (i = 0; i < min; i++)
		new_ptr[i] = old[i];

	free(ptr);

	return (new_ptr);
}
