#include <stdio.h>
#include "Subscriber.h"

void lightingSystemUpdate(Subscriber* self, const char* event) {
    printf("[LightingSystem] Alert: %s\n", event);
}

Subscriber CreateLightingSystem() {
    Subscriber sub;
    sub.update = lightingSystemUpdate;
    return sub;
}
