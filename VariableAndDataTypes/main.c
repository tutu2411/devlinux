#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include ".\Config\config.h"
#include ".\Sensor\sensors.h"
#include ".\Actuators\actuators.h"
#include ".\Buttons\buttons.h"
#include ".\WaterLogic\watering_logic.h"

int main() {
    SystemConfig config;
    loadDefaultConfig(&config);

    int wateringTime = 0;
    SensorData sensorData;

    while (1) {
        // Switch to auto
        if (isAutoTogglePressed()) {
            config.mode = (config.mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
            printf(">> Switched to %s mode\n", config.mode == MODE_AUTO ? "AUTO" : "MANUAL");
            turnPumpOff();
        }

        // Read Config
        sensorData = readSensorData();

        if (config.mode == MODE_AUTO) {
            handleAutoWatering(&sensorData, &config, &wateringTime);
        } else {
            // MANUAL
            setLedState(LED_NORMAL);
            if (isManualWaterPressed()) {
                printf(">> Manual watering for 10s...\n");
                turnPumpOn();
                setLedState(LED_WATERING);
                sleep(10);
                turnPumpOff();
                setLedState(LED_NORMAL);
            }
        }

        sleep(config.sensorInterval);
    }

    return 0;
}
