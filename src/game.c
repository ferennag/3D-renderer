#include "game.h"
#include "engine/color.h"
#include "engine/rect.h"

void initialize() {
}

void update() {
}

void render(Renderer *renderer) {
    renderer_clear_color_buffer(renderer, rgb(0.08f, 0.08f, 0.08f));
    renderer_draw_grid(renderer, 20, rgb(0.15f, 0.15f, 0.15f));
    renderer_draw_rect(renderer, RECT(100, 100, 220, 340), rgb(0.1f, 0.2f, 0.75f));
}

void shutdown() {
}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}