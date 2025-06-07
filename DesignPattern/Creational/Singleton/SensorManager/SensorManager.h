#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

typedef struct {
    void (*collectData)();
    void (*uploadToDatabase)();
} SensorManager;

SensorManager* getSensorManager();

#endif // SENSOR_MANAGER_H
