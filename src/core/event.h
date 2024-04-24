#pragma once

#include "defines.h"

typedef enum EventType {
    EVENT_WINDOW_RESIZED,
    EVENT_KEYPRESS
} EventType;

typedef union EventData {
    u64 data_u64[2];
    u32 data_u32[4];
    u16 data_u16[8];
    u8 data_u8[16];
} EventData;

typedef void (*event_callback)(EventType, EventData);

void event_init();

void event_shutdown();

void event_subscribe(EventType type, event_callback callback);

void event_dispatch(EventType type, EventData data);