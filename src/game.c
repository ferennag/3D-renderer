#include "game.h"
#include "engine/color.h"

void initialize() {
}

void update() {
}

void render(Renderer *renderer) {
    renderer_clear_color_buffer(renderer, rgb(0.1f, 0.1f, 0.1f));
    renderer_draw_grid(renderer, 20, rgb(0.2f, 0.2f, 0.2f));
    renderer_draw_rect(renderer, 100, 100, 220, 340, rgb(0.1f, 0.2f, 0.85f));
}

void shutdown() {
}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}