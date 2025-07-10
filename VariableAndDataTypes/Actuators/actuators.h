#ifndef ACTUATOR_H
#define ACTUATOR_H

typedef enum PumpState {
    PUMP_ON = 0,        // Pump is running
    PUMP_OFF            // Pump is off
} PumpState;

typedef enum SystemMode {
    MODE_AUTO = 0,        // Pump is running
    MODE_MANUAL           // Pump is off
} SystemMode;

typedef enum LedState {
    LED_NORMAL = 0,             // System is normal
    LED_WATERING,               // System is watering
    LED_LOW_MOISTURE_ALERT,     // Moisture is low
    LED_ERROR                   // System error
} LedState;

void turnPumpOn();
void turnPumpOff();
PumpState getPumpState();
void setLedState(LedState state);

#endif