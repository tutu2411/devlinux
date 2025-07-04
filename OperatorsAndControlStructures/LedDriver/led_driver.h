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
void LedSetPixelColor(size_t Index, uint8_t Red, uint8_t Green, uint8_t Blue);
void LedFill(uint8_t Red, uint8_t Green, uint8_t Blue);
size_t LedGetPixelCount();
void ShowPixelInHexa(size_t Index);
void ShowLedInfo();
void ShowLedInfoInHexa();
const uint32_t* GetBuffer();

#endif