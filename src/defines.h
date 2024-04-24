#pragma once

#include <stdint.h>
#include <stdbool.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define f32 float
#define f64 double

_Static_assert(sizeof(u8) == 1, "u8 expected to be 1 byte");
_Static_assert(sizeof(u16) == 2, "u16 expected to be 2 byte");
_Static_assert(sizeof(u32) == 4, "u32 expected to be 4 byte");
_Static_assert(sizeof(u64) == 8, "u64 expected to be 8 byte");

_Static_assert(sizeof(i8) == 1, "i8 expected to be 1 byte");
_Static_assert(sizeof(i16) == 2, "i16 expected to be 2 byte");
_Static_assert(sizeof(i32) == 4, "i32 expected to be 4 byte");
_Static_assert(sizeof(i64) == 8, "i64 expected to be 8 byte");

_Static_assert(sizeof(f32) == 4, "f32 expected to be 4 byte");
_Static_assert(sizeof(f64) == 8, "f64 expected to be 8 byte");

#define NULL 0