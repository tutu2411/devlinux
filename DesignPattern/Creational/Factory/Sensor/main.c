// main.c
#include <stdio.h>
#include <stdlib.h>
#include "SensorFactory.h"

int main() {
    Sensor* tempSensor = createSensor(SENSOR_TEMPERATURE);
    Sensor* humiditySensor = createSensor(SENSOR_HUMIDITY);

    if (tempSensor) {
        if (tempSensor->init(tempSensor) == 0) {
            float temp = tempSensor->readData(tempSensor);
            printf("Temperature: %.2f°C\n", temp);
        }
        free(tempSensor);
    }

    if (humiditySensor) {
        if (humiditySensor->init(humiditySensor) == 0) {
            float hum = humiditySensor->readData(humiditySensor);
            printf("Humidity: %.2f%%\n", hum);
        }
        free(humiditySensor);
    }

    return 0;
}
