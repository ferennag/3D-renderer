#pragma once

#include "defines.h"

typedef u32 Color;

u32 to_hex(f32 value);

Color rgb(f32 r, f32 g, f32 b);

Color rgba(f32 r, f32 g, f32 b, f32 a);

#define RGB(r, g, b) (rgb((r), (g), (b)))
#define RGBA(r, g, b, a) (rgba((r), (g), (b), (a)))