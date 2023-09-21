#include "memory.h"

/**
 * _realloc - A Function which reallocates a memory block
 * using malloc and free.
 * @ptr:- A Pointer to the memory that previously allocated.
 * @old_size: A Size, in bytes, that allocated space for ptr.
 * @new_size: A New size, in bytes of the new memory block.
 * Return: New Memory reallocated.
 ***/

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *siz, *aux;
	unsigned int j;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		siz = malloc(new_size);
		if (siz == NULL)
			return (NULL);
		return (siz);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	siz = malloc(new_size);
	if (siz == NULL)
		return (NULL);

	aux = ptr;
	for (j = 0; j < old_size; j++)
		siz[j] = aux[j];

	free(ptr);

	return (siz);
}
