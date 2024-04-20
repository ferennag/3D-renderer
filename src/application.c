#include "application.h"
#include "engine/renderer.h"
#include "core/memory.h"
#include <stdio.h>
#include <SDL.h>

typedef struct ApplicationContext {
    SDL_Window *window;
    SDL_Renderer *sdl_renderer;
    SDL_Texture *screen_texture;
    Renderer *renderer;
} ApplicationContext;

SDL_Texture *create_sreen_texture(ApplicationContext *context, int width, int height) {
    return SDL_CreateTexture(context->sdl_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height);
}

void application_window_resized(ApplicationContext *context, int width, int height) {
    SDL_DestroyTexture(context->screen_texture);
    context->screen_texture = create_sreen_texture(context, width, height);
    renderer_resize(context->renderer, width, height);
}

ApplicationContext *application_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return NULL;
    }

    ApplicationContext *context = memory_alloc(sizeof(ApplicationContext));

    context->window = SDL_CreateWindow("3D renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 760,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);

    if (!context->window) {
        printf("Error initializing SDL window: %s\n", SDL_GetError());
        return false;
    }

    context->sdl_renderer = SDL_CreateRenderer(context->window, -1, 0);

    if (!context->sdl_renderer) {
        printf("Error initializing SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    int width, height;
    SDL_GetWindowSize(context->window, &width, &height);

    context->screen_texture = create_sreen_texture(context, width, height);
    context->renderer = renderer_create(width, height);

    return context;
}

void application_shutdown(ApplicationContext *context) {
    renderer_destroy(context->renderer);
    context->renderer = NULL;

    SDL_DestroyTexture(context->screen_texture);
    context->screen_texture = NULL;

    SDL_DestroyRenderer(context->sdl_renderer);
    context->sdl_renderer = NULL;

    SDL_DestroyWindow(context->window);
    context->window = NULL;

    SDL_Quit();
    memory_free(context);
}

bool handle_keyboard_event(SDL_KeyboardEvent *event) {
    switch (event->keysym.sym) {
        case SDLK_ESCAPE:
        case SDLK_q:
            return false;
        default:
            return true;
    }
}

bool handle_event(ApplicationContext *context, SDL_Event *event) {
    switch (event->type) {
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            return handle_keyboard_event(&event->key);
        case SDL_WINDOWEVENT:
            if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
                application_window_resized(context, event->window.data1, event->window.data2);
            }
            break;
        default:
            break;
    }

    return true;
}

void application_run(ApplicationContext *context, Game *game) {
    game->initialize();

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            running &= handle_event(context, &event);
        }

        game->update();

        SDL_RenderClear(context->sdl_renderer);
        game->render(context->renderer);

        Framebuffer *buffer = renderer_current_framebuffer(context->renderer);
        SDL_UpdateTexture(context->screen_texture, NULL, buffer->color_buffer, buffer->pitch);
        SDL_RenderCopy(context->sdl_renderer, context->screen_texture, NULL, NULL);
        SDL_RenderPresent(context->sdl_renderer);
    }

    game->shutdown();
}