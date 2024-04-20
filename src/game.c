#include "game.h"
#include "core/color.h"
#include "core/rect.h"
#include "math/vector.h"

const int N_POINTS = 9 * 9 * 9;

Vec3 cube_points[N_POINTS] = {};

void initialize() {
    u32 count = 0;
    for (f32 x = -1.0f; x <= 1.0f; x += 0.25) {
        for (f32 y = -1.0f; y <= 1.0f; y += 0.25) {
            for (f32 z = -1.0f; z <= 1.0f; z += 0.25) {
                cube_points[count++] = VEC3(x, y, z);
            }
        }
    }
}

/// Orthographic projection


void update() {
}

void render(Renderer *renderer) {
    renderer_clear_color_buffer(renderer, RGB(0.08f, 0.08f, 0.08f));
//    renderer_draw_grid(renderer, 20, RGB(0.15f, 0.15f, 0.15f));
//    renderer_draw_rect(renderer, RECT(100, 100, 220, 340), RGB(0.1f, 0.2f, 0.75f));
//    renderer_draw_pixel(renderer, 500, 500, RGB(1.0f, 1.0f, 1.0f));

    for (int i = 0; i < N_POINTS; ++i) {
        Vec3 point = cube_points[i];
        renderer_draw_vertex(renderer, point, RGB(0.3f, 0.4f, 1.0f));
    }
}

void shutdown() {
}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}