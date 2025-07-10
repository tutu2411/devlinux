// SensorFactory.c
#include "SensorFactory.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include <stdlib.h>


Sensor* createSensor(SensorType type) {
    switch (type) {
        case SENSOR_TEMPERATURE:
            return createTemperatureSensor();
        case SENSOR_HUMIDITY:
            return createHumiditySensor();
        default:
            return NULL;
    }
}
