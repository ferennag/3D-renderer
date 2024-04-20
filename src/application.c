#include "application.h"
#include <stdio.h>
#include <SDL.h>

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

bool application_init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Error initializing SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 760,
                                          SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (!window) {
        printf("Error initializing SDL window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        printf("Error initializing SDL renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void application_shutdown() {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
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

bool handle_event(SDL_Event *event) {
    switch (event->type) {
        case SDL_QUIT:
            return false;
        case SDL_KEYDOWN:
            return handle_keyboard_event(&event->key);
        default:
            break;
    }

    return true;
}

void application_run() {
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            running &= handle_event(&event);
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }
}