#pragma once

#include "defines.h"

void *memory_alloc(u64 size);

void memory_free(void *block);

void *memory_copy(void *dst, void *src, u64 size);
