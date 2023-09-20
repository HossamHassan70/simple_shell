#include "memory.h"

/**
 * free_memory_p :- This for Free a pointer.
 * @ptr: A Pointer to free.
 * Return: Void.
 ***/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp :- This for make Free to double pointer.
 * @ptr: A Double pointer to free.
 * Return: Void
 ***/
void free_memory_pp(void **ptr)
{
	void **tmp;

	tmp = ptr;
	while (*tmp != NULL)
	{
		free_memory_p(*tmp);
		tmp++;
	}

	free_memory_p(ptr);
}

