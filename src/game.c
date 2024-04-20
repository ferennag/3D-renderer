#include "game.h"

void initialize() {

}

void update() {

}

void render() {

}

void shutdown() {

}

void game_init(Game *out_game) {
    out_game->initialize = initialize;
    out_game->update = update;
    out_game->render = render;
    out_game->shutdown = shutdown;
}