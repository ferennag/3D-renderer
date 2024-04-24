#include "application.h"
#include <stdio.h>
#include "engine/renderer.h"
#include "core/memory.h"
#include "engine/window.h"
#include "core/event.h"

typedef struct ApplicationContext {
    Window *window;
    Renderer *renderer;
} ApplicationContext;

static ApplicationContext context;

void application_window_resized(EventType type, EventData data) {
    renderer_resize(context.renderer, data.data_u64[0], data.data_u64[1]);
}

bool application_init() {
    event_init();

    context.window = window_create("3D Renderer", 1280, 760);

    if (!context.window) {
        printf("Error initializing application window!\n");
        return false;
    }

    int width, height;
    window_get_size(context.window, &width, &height);
    context.renderer = renderer_create(width, height);

    event_subscribe(EVENT_WINDOW_RESIZED, application_window_resized);

    return true;
}

void application_shutdown() {
    renderer_destroy(context.renderer);
    context.renderer = NULL;

    window_destroy(context.window);
    context.window = NULL;

    event_shutdown();
}

void application_run(Game *game) {
    game->initialize();

    bool running = true;
    while (running) {
        running &= window_poll_events(context.window);

        game->update();
        game->render(context.renderer);

        Framebuffer *buffer = renderer_current_framebuffer(context.renderer);
        window_render_frame(context.window, buffer);
    }

    game->shutdown();
}