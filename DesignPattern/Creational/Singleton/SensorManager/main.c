#include <stdio.h>
#include "SensorManager.h"

int main() {
    SensorManager* sensorManager = getSensorManager();

    sensorManager ->collectData();
    sensorManager ->uploadToDatabase();

    // Get another Sensor Manager instance
    SensorManager* sensorManager2 = getSensorManager();

    return 0;
}
