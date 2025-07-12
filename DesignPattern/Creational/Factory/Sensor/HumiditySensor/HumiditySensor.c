#include <stdio.h>
#include <stdlib.h>
#include "HumiditySensor.h"

static int humiditySensorInit() {
    printf("Initializing Humidity Sensor...\n");
    return 0;
}

static float humiditySensorReadData() {
    printf("Reading Humidity Sensor...\n");
    return 60.0f; // Dummy humidity value
}

Sensor* createHumiditySensor() {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    if (sensor) {
        sensor->init = humiditySensorInit;
        sensor->readData = humiditySensorReadData;
    }
    return sensor;
}
