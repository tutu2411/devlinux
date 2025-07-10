#include <stdio.h>
#include "watering_logic.h"
#include "..\Actuators\actuators.h"
#include "..\Sensor\sensor.h"

void handleAutoWatering(SensorData sensorData, int* wateringTime) {
    if (sensorData.soilMoisture < 10) {
        if (*wateringTime < 10) {
            turnPumpOn();
            setLedState(LED_WATERING);
            (*wateringTime)++;
        } else {
            printf("[Warning] Max watering time reached.\n");
            turnPumpOff();
        }
    } else if (sensorData.soilMoisture > 30) {
        turnPumpOff();
        setLedState(LED_NORMAL);
        *wateringTime = 0;
    } else {
        setLedState(LED_NORMAL);
        turnPumpOff();
        *wateringTime = 0;
    }
}
