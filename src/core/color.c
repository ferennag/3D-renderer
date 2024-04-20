#include "color.h"
#include <math.h>
#include "math/math.h"

inline u32 to_hex(f32 value) {
    u32 f = (u32) roundf(value * 255);
    return (u32) MIN(MAX(0, f), 255);
}

inline Color rgb(f32 r, f32 g, f32 b) {
    return rgba(r, g, b, 1.0f);
}

inline Color rgba(f32 r, f32 g, f32 b, f32 a) {
    return (to_hex(r) << 24) | (to_hex(g) << 16) | (to_hex(b) << 8) | to_hex(a);
}