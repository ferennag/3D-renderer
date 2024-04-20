#include "renderer.h"
#include "framebuffer.h"
#include "core/memory.h"

typedef struct Renderer {
    Framebuffer *framebuffer;
} Renderer;

Renderer *renderer_create(u32 width, u32 height) {
    Renderer *renderer = memory_alloc(sizeof(Renderer));
    renderer->framebuffer = framebuffer_create(width, height);
    return renderer;
}

void renderer_destroy(Renderer *renderer) {
    framebuffer_destroy(renderer->framebuffer);
    renderer->framebuffer = NULL;

    memory_free(renderer);
}

void renderer_resize(Renderer *renderer, u32 width, u32 height) {
    framebuffer_destroy(renderer->framebuffer);
    renderer->framebuffer = framebuffer_create(width, height);
}

void renderer_clear_color_buffer(Renderer *renderer, Color color) {
    Framebuffer *buffer = renderer->framebuffer;
    for (u32 row = 0; row < buffer->height; ++row) {
        for (u32 col = 0; col < buffer->width; ++col) {
            u64 pos = row * buffer->width + col;
            buffer->color_buffer[pos] = color;
        }
    }
}

Framebuffer *renderer_current_framebuffer(Renderer *renderer) {
    return renderer->framebuffer;
}

void renderer_draw_pixel(Renderer *renderer, u32 x, u32 y, Color color) {
    Framebuffer *buffer = renderer_current_framebuffer(renderer);
    framebuffer_set_color(buffer, x, y, color);
}

void renderer_draw_grid(Renderer *renderer, u32 size, Color color) {
    Framebuffer *buffer = renderer_current_framebuffer(renderer);
    for (u32 row = 0; row < buffer->height; ++row) {
        for (u32 col = 0; col < buffer->width; ++col) {
            if (col % size == 0 || row % size == 0) {
                framebuffer_set_color(buffer, col, row, color);
            }
        }
    }
}

void renderer_draw_rect(Renderer *renderer, Rect bounds, Color color) {
    for (u32 row = bounds.y; row < bounds.h; ++row) {
        for (u32 col = bounds.x; col < bounds.w; ++col) {
            framebuffer_set_color(renderer->framebuffer, col, row, color);
        }
    }
}