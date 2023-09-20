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
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
	{
		return (NULL);
	}

	if (ptr != NULL)
	{
		size_t copy_size = old_size < new_size ? old_size : new_size;

		memcpy(new_ptr, ptr, copy_size);
		free(ptr);
	}

	return (new_ptr);
}
