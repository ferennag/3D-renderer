#pragma once

#include "defines.h"
#include "framebuffer.h"

typedef struct Renderer Renderer;

Renderer *renderer_create(u32 width, u32 height);

void renderer_destroy(Renderer *renderer);

void renderer_resize(Renderer *renderer, u32 width, u32 height);

void renderer_clear_color_buffer(Renderer *renderer, u32 color);

Framebuffer *renderer_current_framebuffer(Renderer *renderer);