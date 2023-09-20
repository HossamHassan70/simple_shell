#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include <string.h>

/**=== memory.c ===**/
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/**=== free.c ===**/
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);

#endif /**== MEMORY_H ==**/
