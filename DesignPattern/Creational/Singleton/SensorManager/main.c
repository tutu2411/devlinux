#include <stdio.h>
#include "SensorManager.h"

int main() {
    SensorManager* sensorManager = GetSensorManager();

    sensorManager ->collectData();
    sensorManager ->uploadToDatabase();

    // Get another Sensor Manager instance
    SensorManager* sensorManager2 = GetSensorManager();

    return 0;
}
