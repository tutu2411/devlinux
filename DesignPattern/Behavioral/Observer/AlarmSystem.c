#include <stdio.h>
#include "Subscriber.h"

void AlarmSystemUpdate(Subscriber* self, const char* event) {
    printf("[AlarmSystem] Alert: %s\n", event);
}

Subscriber CreateAlarmSystem() {
    Subscriber sub;
    sub.update = AlarmSystemUpdate;
    return sub;
}
