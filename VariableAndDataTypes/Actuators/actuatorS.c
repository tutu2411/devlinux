#include <stdio.h>
#include "actuators.h"

static PumpState pumpState = PUMP_OFF;

void turnPumpOn() {
    if (pumpState == PUMP_OFF) {
        pumpState = PUMP_ON;
        printf("[Pump] ON\n");
    }
}

void turnPumpOff() {
    if (pumpState == PUMP_ON) {
        pumpState = PUMP_OFF;
        printf("[Pump] OFF\n");
    }
}

PumpState getPumpState() {
    return pumpState;
}

void setLedState(LedState state) {
    const char* color = "UNKNOWN";
    switch (state) {
        case LED_NORMAL: color = "GREEN"; break;
        case LED_WATERING: color = "YELLOW"; break;
        case LED_LOW_MOISTURE_ALERT: color = "BLUE"; break;
        case LED_ERROR: color = "RED"; break;
        default: break; 
    }
    printf("[LED] State: %s\n", color);
}
