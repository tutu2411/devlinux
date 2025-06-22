#include <stdlib.h>
#include <stdio.h>
#include "smart_home_facade.h"

void activateMorningRoutine(SmartHomeFacade* facade) {
    facade->lighting->turnOn();                 // Turn lighting system on
    facade->lighting->setBrightness(90);        // Set Brighness to 100
    facade->hvac->setTemperature(25);           // Set Temperature to 22
    facade->hvac->setMode(HVAC_MODE_COOL);      // Set HVAC Mode to Cool
    facade->security->deactivateAlarm();        // Deactivate Alarm

    printf("Morning Routine activated. \n");
}

void activateAwayMode(SmartHomeFacade* facade) {
    facade->lighting->turnOff();                // Turn lighting system on
    facade->security->activateAlarm();          // Activate Alarm system
    facade->hvac->setTemperature(30);           // Set Temperature to 30
    facade->hvac->setMode(HVAC_MODE_ECO);       // Set HVAC Mode to ECO
    facade->security->deactivateAlarm();        // Deactivate Alarm
    facade->security->monitorSensor();          // Monitor sensors

    printf("Away Mode activated. \n");
}

void setMovieNightScene(SmartHomeFacade* facade) {
    facade->lighting->setBrightness(40);        // Set Brightness to 40
    facade->hvac->setTemperature(21);           // Set Temperature to 21
    facade->hvac->setMode(HVAC_MODE_FAN);       // Set HVAC Mode to COOL
    
    printf("Movie Night Scene activated. \n");
}

SmartHomeFacade* createSmartHomeFacade() {
    SmartHomeFacade* smartHomeFacade = malloc(sizeof(SmartHomeFacade));
    smartHomeFacade->lighting = createLightingSystem();
    smartHomeFacade->security = createSecuritySystem();
    smartHomeFacade->hvac = createHvacSystem();
    return smartHomeFacade;
}