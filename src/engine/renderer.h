#pragma once

#include "defines.h"
#include "framebuffer.h"
#include "color.h"

typedef struct Renderer Renderer;

Renderer *renderer_create(u32 width, u32 height);

void renderer_destroy(Renderer *renderer);

void renderer_resize(Renderer *renderer, u32 width, u32 height);

void renderer_clear_color_buffer(Renderer *renderer, Color color);

Framebuffer *renderer_current_framebuffer(Renderer *renderer);

void renderer_draw_grid(Renderer *renderer, u32 size, Color color);

void renderer_draw_rect(Renderer *renderer, u32 x, u32 y, u32 w, u32 h, Color color);