#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor.h"

SensorData readSensorData() {
    SensorData data;
    data.soilMoisture = rand() % 101;
    data.temperature = 20.0f + rand() % 150 / 10.0f;
    printf("[Sensor] Moisture: %d%%, Temp: %.1f°C\n", data.soilMoisture, data.temperature);
    return data;
}
