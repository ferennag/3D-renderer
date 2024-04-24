#include <stdio.h>
#include "application.h"
#include "game.h"

int main(void) {
    if (!application_init()) {
        printf("Failed to initialize application!\n");
        return -1;
    }

    Game game = {0};
    game_init(&game);

    application_run(&game);

    application_shutdown();
    return 0;
}
