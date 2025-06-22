#include <stdlib.h>
#include <stdio.h>
#include "Facade\smart_home_facade.h"


int main() {
    SmartHomeFacade* smartHome = createSmartHomeFacade();
    
    printf(">>> Activate Morning Routine...\n");
    activateMorningRoutine(smartHome);
    
    printf(">>> Activate Away Mode...\n");
    activateAwayMode(smartHome);
    
    printf(">>> Set Movie Night Scence...\n");
    setMovieNightScene(smartHome);
    
    // Free resource 
    free(smartHome->hvac);
    free(smartHome->lighting);
    free(smartHome->security);
    free(smartHome);
    return 0;
}