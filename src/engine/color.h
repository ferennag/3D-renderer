#pragma once

#include "defines.h"

typedef u32 Color;

u32 to_hex(f32 value);

Color rgb(f32 r, f32 g, f32 b);

Color rgba(f32 r, f32 g, f32 b, f32 a);