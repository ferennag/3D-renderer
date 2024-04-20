#include "game.h"

void initialize() {
}

void update() {
}

void render(Renderer *renderer) {
    renderer_clear_color_buffer(renderer, 0xFF0000);
}

void shutdown() {
}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}