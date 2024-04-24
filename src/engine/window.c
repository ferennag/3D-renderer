#include "window.h"
#include "core/memory.h"

SDL_Texture *window_create_sreen_texture(Window *window, int width, int height);

static bool sdl_initialized = false;

bool handle_keyboard_event(SDL_KeyboardEvent *event) {
    switch (event->keysym.sym) {
        case SDLK_ESCAPE:
        case SDLK_q:
            return false;
        default:
            return true;
    }
}

bool handle_event(Window *window, SDL_Event *event) {
    switch (event->type) {
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            return handle_keyboard_event(&event->key);
        case SDL_WINDOWEVENT:
            if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
                SDL_DestroyTexture(window->screen_texture);
                window->screen_texture = window_create_sreen_texture(window, event->window.data1, event->window.data2);
            }
            break;
        default:
            break;
    }

    return true;
}

Window *window_create(const char *title, int width, int height) {
    if (!sdl_initialized) {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            printf("Error initializing SDL: %s\n", SDL_GetError());
            return NULL;
        }

        sdl_initialized = true;
    }

    Window *window = memory_alloc(sizeof(Window));

    window->sdl_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

    if (!window->sdl_window) {
        printf("Error initializing SDL window: %s\n", SDL_GetError());
        return NULL;
    }

    window->sdl_renderer = SDL_CreateRenderer(window->sdl_window, -1, 0);

    if (!window->sdl_renderer) {
        printf("Error initializing SDL renderer: %s\n", SDL_GetError());
        return NULL;
    }

    int w;
    int h;
    window_get_size(window, &w, &h);
    window->screen_texture = window_create_sreen_texture(window, w, h);

    return window;
}

void window_destroy(Window *window) {
    SDL_DestroyTexture(window->screen_texture);
    window->screen_texture = NULL;

    SDL_DestroyRenderer(window->sdl_renderer);
    window->sdl_renderer = NULL;

    SDL_DestroyWindow(window->sdl_window);
    window->sdl_window = NULL;

    SDL_Quit();
    sdl_initialized = false;
}

SDL_Texture *window_create_sreen_texture(Window *window, int width, int height) {
    return SDL_CreateTexture(window->sdl_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, width,
                             height);
}

void window_get_size(Window *window, int *width, int *height) {
    SDL_GetWindowSize(window->sdl_window, width, height);
}

bool window_poll_events(Window *window) {
    bool running = true;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        running &= handle_event(window, &event);
    }

    return running;
}

void window_render_frame(Window *window, Framebuffer *frame_buffer) {
    SDL_RenderClear(window->sdl_renderer);
    SDL_UpdateTexture(window->screen_texture, NULL, frame_buffer->color_buffer, frame_buffer->pitch);
    SDL_RenderCopy(window->sdl_renderer, window->screen_texture, NULL, NULL);
    SDL_RenderPresent(window->sdl_renderer);
}