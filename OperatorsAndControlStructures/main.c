#include "LedDriver\led_driver.h"

int main()
{
    // Led pixel initialize
    LedInit(10);
    
    // Set pixel index 0 to RED
    LedSetPixelColor(0, 255, 0, 0);

    // Set pixel index 9 to BLUE
    LedSetPixelColor(9, 0, 0, 255);

    // Set pixel index 4 to WHITE
    LedSetPixelColor(4, 255, 255, 255);
    ShowLedInfo();

    // Show pixel 0,4,9
    ShowPixelInHexa(0);
    ShowPixelInHexa(4);
    ShowPixelInHexa(9);
    
    // Set all pixel to BLUE
    LedFill(0, 255, 0);

    // Show all led info in hexa
    ShowLedInfoInHexa();
    
    // Free memory
    LedShutdown();
}