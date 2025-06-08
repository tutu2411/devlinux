// HumiditySensor.c
#include <stdio.h>
#include <stdlib.h>
#include "HumiditySensor.h"

// Implementation of init function
static int humiditySensorInit() {
    printf("Initializing Humidity Sensor...\n");
    return 0;
}

// Implementation of readData function
static float humiditySensorReadData() {
    printf("Reading Humidity Sensor...\n");
    return 60.0f; // Dummy humidity value
}

// Factory function
Sensor* createHumiditySensor() {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    if (sensor) {
        sensor->init = humiditySensorInit;
        sensor->readData = humiditySensorReadData;
    }
    return sensor;
}
