#pragma once

#include "defines.h"
#include "color.h"

typedef struct Framebuffer {
    u32 *color_buffer;
    u32 width, height;
    u32 pitch;
} Framebuffer;

Framebuffer *framebuffer_create(u32 width, u32 height);

void framebuffer_destroy(Framebuffer *framebuffer);

void framebuffer_set_color(Framebuffer *framebuffer, int x, int y, Color color);
