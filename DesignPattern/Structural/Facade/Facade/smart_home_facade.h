#ifndef SMART_HOME_FACADE
#define SMART_HOME_FACADE

#include "../Lighting/lighting_system.h"
#include "../HVAC/hvac_system.h"
#include "../Security/sercurity_system.h"

typedef struct SmartHomeFacade {   
    LightingSystem* lighting;
    SecuritySystem* security;
    HvacSystem* hvac;
} SmartHomeFacade;

SmartHomeFacade* createSmartHomeFacade();
void activateMorningRoutine(SmartHomeFacade* facade);
void activateAwayMode(SmartHomeFacade* facade);
void setMovieNightScene(SmartHomeFacade* facade);

#endif