#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

typedef struct Subscriber {
    void (*update)(struct Subscriber*, const char* event);
} Subscriber;

#endif
