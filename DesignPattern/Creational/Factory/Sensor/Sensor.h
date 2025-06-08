// Sensor.h
#ifndef SENSOR_H
#define SENSOR_H

typedef struct Sensor {
    int (*init)(struct Sensor* self);          // Initialize the sensor
    float (*readData)(struct Sensor* self);    // Read sensor data
} Sensor;

#endif
