#include "application.h"
#include <stdio.h>
#include "engine/renderer.h"
#include "core/memory.h"
#include "engine/window.h"


typedef struct ApplicationContext {
    Window *window;
    Renderer *renderer;
} ApplicationContext;

void application_window_resized(ApplicationContext *context, int width, int height) {
    renderer_resize(context->renderer, width, height);
}

ApplicationContext *application_init() {
    ApplicationContext *context = memory_alloc(sizeof(ApplicationContext));

    context->window = window_create("3D Renderer", 1280, 760);

    if (!context->window) {
        printf("Error initializing application window!\n");
        return false;
    }

    int width, height;
    window_get_size(context->window, &width, &height);
    context->renderer = renderer_create(width, height);

    return context;
}

void application_shutdown(ApplicationContext *context) {
    renderer_destroy(context->renderer);
    context->renderer = NULL;

    window_destroy(context->window);
    context->window = NULL;

    memory_free(context);
}

void application_run(ApplicationContext *context, Game *game) {
    game->initialize();

    bool running = true;
    while (running) {
        running &= window_poll_events(context->window);

        game->update();
        game->render(context->renderer);

        Framebuffer *buffer = renderer_current_framebuffer(context->renderer);
        window_render_frame(context->window, buffer);
    }

    game->shutdown();
}