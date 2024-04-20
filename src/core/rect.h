#pragma once

#include "defines.h"

typedef struct Rect {
    i32 x, y, w, h;
} Rect;

#define RECT(x, y, w, h) ((Rect){(x),(y),(w),(h)})
