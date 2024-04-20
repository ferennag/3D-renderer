#pragma once

typedef struct Game {
    void (*initialize)();

    void (*update)();

    void (*render)();

    void (*shutdown)();
} Game;

void game_init(Game *out_game);