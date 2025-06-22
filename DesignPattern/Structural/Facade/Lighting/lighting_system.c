#include <stdlib.h>
#include <stdio.h>
#include "lighting_system.h"

static void turnOn(){
    printf("Turn lighting system ON. \n");
}

static void turnOff(){
    printf("Turn lighting system OFF. \n");
}

static void setBrightness(int level){
    printf("Setting brightness to: %d\n", level);
}

LightingSystem* createLightingSystem() {
    LightingSystem* lightingSystem = malloc(sizeof(LightingSystem));
    lightingSystem->turnOn = turnOn;
    lightingSystem->turnOff = turnOff;
    lightingSystem->setBrightness = setBrightness;
    return lightingSystem;
}