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

void renderer_clear_color_buffer(Renderer *renderer, u32 color) {
    Framebuffer *buffer = renderer->framebuffer;
    for (int row = 0; row < buffer->width; ++row) {
        for (int col = 0; col < buffer->width; ++col) {
            u64 pos = row * buffer->width + col;
            buffer->color_buffer[pos] = color;
        }
    }
}

Framebuffer *renderer_current_framebuffer(Renderer *renderer) {
    return renderer->framebuffer;
}