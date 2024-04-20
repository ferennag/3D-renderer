#include <stdio.h>
#include "application.h"
#include "game.h"

int main(void) {
    ApplicationContext *application_context = application_init();
    if (!application_context) {
        printf("Failed to initialize application!");
        return -1;
    }

    Game game = {0};
    game_init(&game);

    application_run(application_context, &game);

    application_shutdown(application_context);
    return 0;
}
