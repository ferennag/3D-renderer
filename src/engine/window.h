#pragma once

#include "defines.h"
#include "framebuffer.h"
#include <SDL.h>

typedef struct Window {
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;
    SDL_Texture *screen_texture;
} Window;

Window *window_create(const char *title, int width, int height);

void window_destroy(Window *window);

void window_get_size(Window *window, int *width, int *height);

bool window_poll_events(Window *window);

void window_render_frame(Window *window, Framebuffer *frame_buffer);