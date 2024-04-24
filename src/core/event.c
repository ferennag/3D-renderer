#include "event.h"
#include "darray.h"

typedef struct Subscriber {
    EventType type;
    event_callback callback;
} Subscriber;

typedef struct EventContext {
    Subscriber *subscribers;
} EventContext;

static EventContext event_context;

void event_init() {
    event_context.subscribers = darray_create(Subscriber);
}

void event_shutdown() {
    darray_destroy(event_context.subscribers);
    event_context.subscribers = NULL;
}

void event_subscribe(EventType type, event_callback callback) {
    Subscriber subscriber = {
            .type = type,
            .callback = callback
    };

    darray_push(event_context.subscribers, subscriber);
}

void event_dispatch(EventType type, EventData data) {
    for (int i = 0; i < darray_length(event_context.subscribers); ++i) {
        Subscriber *subscriber = &event_context.subscribers[i];
        if (subscriber->type == type) {
            subscriber->callback(type, data);
        }
    }
}