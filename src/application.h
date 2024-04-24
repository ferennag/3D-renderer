#pragma once

#include "defines.h"
#include <stdbool.h>
#include "game.h"


bool application_init();

void application_shutdown();

void application_run(Game *game);