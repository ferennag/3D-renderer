#pragma once

#include "defines.h"
#include <stdbool.h>
#include "game.h"

typedef struct ApplicationContext ApplicationContext;

ApplicationContext *application_init();

void application_shutdown(ApplicationContext *context);

void application_run(ApplicationContext *context, Game *game);