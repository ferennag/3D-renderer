#include "game.h"

void initialize() {
}

void update() {
}

void draw_grid(Renderer *renderer, u32 color, u32 size) {
    Framebuffer *buffer = renderer_current_framebuffer(renderer);
    for (int row = 0; row < buffer->height; ++row) {
        for (int col = 0; col < buffer->width; ++col) {
            if (col % size == 0 || row % size == 0) {
                framebuffer_set_color(buffer, col, row, color);
            }
        }
    }
}

void render(Renderer *renderer) {
    renderer_clear_color_buffer(renderer, 0x992222);
    draw_grid(renderer, 0x111111, 30);
}

void shutdown() {
}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}