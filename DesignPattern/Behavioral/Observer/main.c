#include "\Sensor\Sensor.h"
#include "\Subscriber\Subscriber.h"
#include <stdio.h>

// Declare the factory functions
Subscriber CreateMobileApp();
Subscriber CreateAlarmSystem();
Subscriber CreateLightingSystem();

int main() {
    Sensor doorSensor;
    Sensor temperatureSensor;
    Sensor_init(&doorSensor);
    Sensor_init(&temperatureSensor);

    Subscriber mobileApp = CreateMobileApp();
    Subscriber alarmSystem = CreateAlarmSystem();
    Subscriber lighting = CreateLightingSystem();

    doorSensor.subscribe(&doorSensor, &mobileApp);
    doorSensor.subscribe(&doorSensor, &alarmSystem);
    doorSensor.subscribe(&doorSensor, &lighting);

    // Simulate door open event
    doorSensor.notifySubscribers(&doorSensor, "Front door opened at 00:30");

    printf("unsubscribe [Alarm System] with [DoorSensor] \n");

    doorSensor.unsubscribe(&doorSensor, &alarmSystem);

    doorSensor.notifySubscribers(&doorSensor, "Front door opened at 11:30");

    printf("subscribe  [Alarm System] & [Mobile app] with [Temperature Sensor] \n");

    temperatureSensor.subscribe(&temperatureSensor, &alarmSystem);
    temperatureSensor.subscribe(&temperatureSensor, &mobileApp);

    doorSensor.notifySubscribers(&doorSensor, "Front door opened at 11:40");

    temperatureSensor.notifySubscribers(&temperatureSensor, "Temperature too high at 23:59");

    return 0;
}
