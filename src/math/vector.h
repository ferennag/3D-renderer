#pragma once

#include "defines.h"

#define VEC2(x, y) ((Vec2) {(x), (y)})
#define VEC3(x, y, z) ((Vec3) {(x), (y), (z)})
#define VEC4(x, y, z, w) ((Vec4) {(x), (y), (z), (w)})

typedef struct Vec2 {
    f32 x, y;
} Vec2;

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Vec4 {
    f32 x, y, z, w;
} Vec4;
