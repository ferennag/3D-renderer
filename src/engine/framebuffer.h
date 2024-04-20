#pragma once

#include "defines.h"

typedef struct Framebuffer {
    u32 *color_buffer;
    u32 width, height;
    u32 pitch;
} Framebuffer;

Framebuffer *framebuffer_create(u32 width, u32 height);

void framebuffer_destroy(Framebuffer *framebuffer);
