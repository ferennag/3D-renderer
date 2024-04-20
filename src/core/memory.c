#include "memory.h"
#include <stdlib.h>
#include <string.h>

void *memory_alloc(u64 size) {
    return calloc(1, size);
}

void memory_free(void *block) {
    free(block);
}

void *memory_copy(void *dst, void *src, u64 size) {
    return memcpy(dst, src, size);
}