#ifndef SENSOR_H
#define SENSOR_H

#include "Subscriber.h"

#define MAX_SUBSCRIBERS 10

// Forward declaration + typedef
typedef struct Sensor Sensor;

struct Sensor{
    Subscriber* subscribers[MAX_SUBSCRIBERS];
    int subscriberCount;

    void (*subscribe)(struct Sensor*, Subscriber*);
    void (*unsubscribe)(struct Sensor*, Subscriber*);
    void (*notifySubscribers)(struct Sensor*, const char* event);
};

void Sensor_init(Sensor* sensor);

#endif
