#include "LedDriver\led_driver.h"


int main()
{
    ledInit(10);
    // Set pixel index 0 to RED
    ledSetPixelColor(0, 255, 0, 0);

    // Set pixel index 9 to BLUE
    ledSetPixelColor(9, 0, 0, 255);

    // Set pixel index 4 to WHITE
    ledSetPixelColor(4, 255, 255, 255);
    showLedInfo();

    showPixelInfo2(0);
    showPixelInfo2(4);
    showPixelInfo2(9);

    ledFill(0, 255, 0);

    showLedInfo2();

    ledShutdown();
}