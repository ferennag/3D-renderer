#pragma once
#include <SDL.h>
#include "engine/renderer.h"

typedef struct Game {
    void (*initialize)();

    void (*update)();

    void (*render)(Renderer *renderer);

    void (*shutdown)();
} Game;

void game_init(Game *out_game);