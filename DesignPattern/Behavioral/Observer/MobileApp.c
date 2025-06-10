#include <stdio.h>
#include "Subscriber.h"

void mobileAppUpdate(Subscriber* self, const char* event) {
    printf("[MobileApp] Alert: %s\n", event);
}

Subscriber CreateMobileApp() {
    Subscriber sub;
    sub.update = mobileAppUpdate;
    return sub;
}
