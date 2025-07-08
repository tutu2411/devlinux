#include <string.h>
#include "Sensor.h"

static void subscribe(Sensor* sensor, Subscriber* sub) {
    if (sensor->subscriberCount < MAX_SUBSCRIBERS) {
        sensor->subscribers[sensor->subscriberCount++] = sub;
    }
}

static void unsubscribe(Sensor* sensor, Subscriber* sub) {
    for (int i = 0; i < sensor->subscriberCount; ++i) {
        if (sensor->subscribers[i] == sub) {
            for (int j = i; j < sensor->subscriberCount - 1; ++j) {
                sensor->subscribers[j] = sensor->subscribers[j + 1];
            }
            sensor->subscriberCount--;
            break;
        }
    }
}

static void notifySubscribers(Sensor* sensor, const char* event) {
    for (int i = 0; i < sensor->subscriberCount; ++i) {
        sensor->subscribers[i]->update(sensor->subscribers[i], event);
    }
}

void Sensor_init(Sensor* sensor) {
    sensor->subscriberCount = 0;
    sensor->subscribe = subscribe;
    sensor->unsubscribe = unsubscribe;
    sensor->notifySubscribers = notifySubscribers;
}
