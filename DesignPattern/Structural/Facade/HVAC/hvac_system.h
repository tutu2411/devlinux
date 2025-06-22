#ifndef HVAC_SYSTEM_H
#define HVAC_SYSTEM_H

typedef enum HvacMode{
    HVAC_MODE_COOL,
    HVAC_MODE_HEAT,
    HVAC_MODE_FAN,
    HVAC_MODE_ECO,
    HVAC_MODE_INVALID
} HvacMode;

typedef struct  HvacSystem {
    void (*setTemperature)(int temperature);
    void (*setMode)(HvacMode mode);
} HvacSystem;

HvacSystem* createHvacSystem();

#endif