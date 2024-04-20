#pragma once

#include "defines.h"
#include "framebuffer.h"
#include "core/color.h"
#include "core/rect.h"
#include "math/vector.h"

typedef struct Renderer Renderer;

Renderer *renderer_create(u32 width, u32 height);

void renderer_destroy(Renderer *renderer);

void renderer_resize(Renderer *renderer, u32 width, u32 height);

Framebuffer *renderer_current_framebuffer(Renderer *renderer);

/*
 * Rendering functions
 */

void renderer_clear_color_buffer(Renderer *renderer, Color color);

void renderer_draw_grid(Renderer *renderer, u32 size, Color color);

void renderer_draw_pixel(Renderer *renderer, u32 x, u32 y, Color color);

void renderer_draw_rect(Renderer *renderer, Rect rect, Color color);

/*
 * 3D rendering
 */

void renderer_draw_vertex(Renderer *renderer, Vec3 vertex, Color color);