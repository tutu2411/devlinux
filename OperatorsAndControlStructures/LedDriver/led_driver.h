#ifndef LED_DRIVER
#define LED_DRIVER

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


typedef enum RESULT{
    FAILED = -1,
    SUUCCESS
} RESULT;

int ledInit(size_t numPixels);
void ledShutdown();
void ledClear();
const uint32_t* ledGetBuffer();
void ledSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue);
void ledFill(uint8_t red, uint8_t green, uint8_t blue);
size_t ledGetPixelCount();
void showPixelInfo2(size_t index);
void showLedInfo();
void showLedInfo2();

#endif