#include "framebuffer.h"
#include <stdio.h>
#include "core/memory.h"

Framebuffer *framebuffer_create(u32 width, u32 height) {
    Framebuffer *framebuffer = memory_alloc(sizeof(Framebuffer));

    framebuffer->color_buffer = memory_alloc((width * height) * sizeof(u32));
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pitch = sizeof(u32) * width;

    return framebuffer;
}

void framebuffer_destroy(Framebuffer *framebuffer) {
    memory_free(framebuffer->color_buffer);
    framebuffer->color_buffer = NULL;
    memory_free(framebuffer);
}

inline void framebuffer_set_color(Framebuffer *framebuffer, int x, int y, u32 color) {
    if (x < 0 || y < 0 || x > framebuffer->width || y > framebuffer->height) {
        printf("Warning: trying to index framebuffer of size (%d, %d) with (%d, %d)\n", framebuffer->width,
               framebuffer->height, x, y);
        return;
    }

    u32 position = y * framebuffer->width + x;
    framebuffer->color_buffer[position] = color;
}