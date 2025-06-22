#include <stdlib.h>
#include <stdio.h>
#include "hvac_system.h"

static void setTemperature(int temperature)
{
    printf("Setting temperature to: %d°C\n", temperature);
}

static void setMode(HvacMode mode)
{
    switch (mode)
    {
        case HVAC_MODE_COOL:
            printf("Switching to COOL mode.\n");
            break;
        case HVAC_MODE_HEAT:
            printf("Switching to HEAT mode.\n");
            break;
        case HVAC_MODE_FAN:
            printf("Switching to FAN mode.\n");
            break;
        case HVAC_MODE_ECO:
            printf("Switching to ECO mode.\n");
            break;
        default:
            printf("Invalid HVAC mode.\n");
            return;
    }
}

HvacSystem* createHvacSystem()
{
    HvacSystem* hvavSystem = malloc(sizeof(HvacSystem));;
    hvavSystem->setTemperature = setTemperature;
    hvavSystem->setMode = setMode;
    return hvavSystem;
}
