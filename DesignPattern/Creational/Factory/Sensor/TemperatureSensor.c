// TemperatureSensor.c
#include <stdio.h>
#include <stdlib.h>
#include "TemperatureSensor.h"

// Implementation of init function
static int tempSensorInit() {
    printf("Initializing Temperature Sensor...\n");
    return 0;
}

// Implementation of readData function
static float tempSensorReadData() {
    printf("Reading Temperature Sensor...\n");
    return 25.5f; // Dummy temperature value
}

// Factory function
Sensor* createTemperatureSensor() {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    if (sensor) {
        sensor->init = tempSensorInit;
        sensor->readData = tempSensorReadData;
    }
    return sensor;
}
