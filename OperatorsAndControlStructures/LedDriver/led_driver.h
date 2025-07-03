#ifndef LED_DRIVER
#define LED_DRIVER

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


typedef enum RESULT{
    FAILED = -1,
    SUUCCESS
} RESULT;

int LedInit(size_t numPixels);
void LedShutdown();
void LedClear();
const uint32_t* LedGetBuffer();
void LedSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue);
void LedFill(uint8_t red, uint8_t green, uint8_t blue);
size_t LedGetPixelCount();
void ShowPixelInfo2(size_t index);
void ShowLedInfo();
void ShowLedInfo2();

#endif