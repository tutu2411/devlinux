#include <stdlib.h>
#include <stdio.h>
#include "sercurity_system.h"

static void activateAlarm() {
    printf("Alarm activated. \n");
}

static void deactivateAlarm() {
    printf("Alarm deactivated. \n");
}

static void monitorSensor() {
    printf("Monitoring sensors...\n");
}

SecuritySystem* createSecuritySystem(){
    SecuritySystem* securitySystem = malloc(sizeof(SecuritySystem));
    securitySystem->activateAlarm = activateAlarm;
    securitySystem->deactivateAlarm = deactivateAlarm;
    securitySystem->monitorSensor = monitorSensor;
    return securitySystem;
}