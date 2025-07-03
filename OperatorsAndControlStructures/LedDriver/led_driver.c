#include "led_driver.h"

static uint32_t* ledBuffer = NULL;
static size_t ledCount = 0;

int LedInit(size_t numPixel) {

    if (numPixel == 0) return FAILED;

    ledBuffer = (uint32_t*)malloc(numPixel * sizeof(uint32_t));
    if (ledBuffer == NULL) return FAILED;

    ledCount = numPixel;
    printf("Create %d pixel success\n", numPixel);
    LedClear();
    printf("Clear led success\n");

    return SUUCCESS;
}

void LedSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue) {
    
    if (index > ledCount) return;
    ledBuffer[index] = blue + (red << 8) + (green << 16);
}

void LedShutdown() {
    if (ledBuffer != NULL) {
        printf("memory has been free");
        free(ledBuffer);
        ledBuffer = NULL;
    }
}

void LedClear() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            ledBuffer[i] = 0;
        }
    }
}

void LedFill(uint8_t red, uint8_t green, uint8_t blue) {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            LedSetPixelColor(i, red, green, blue);
        }
    }
}

const uint32_t* GetBuffer(){
    return ledBuffer;
}

size_t LedGetPixelCount() {
    return ledCount;
}

void ShowPixelInfo(size_t index) {

    if (index > ledCount) return;
    uint32_t pixel = ledBuffer[index];

    uint32_t blue = (pixel >> 0) & 0xFF;
    uint32_t red = (pixel >> 8) & 0xFF;
    uint32_t green = (pixel >> 16) & 0xFF;

    printf("PIXEL %d: GREEN %u RED %u BLUE %u\n",index, green, red, blue);
}

void ShowPixelInfo2(size_t index) {

    if (index > ledCount) return;
    uint32_t pixel = ledBuffer[index];

    printf("PIXEL %d: value 0x%08X\n",index, pixel);
}

void ShowLedInfo() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            ShowPixelInfo(i);
        }
    }
}

void ShowLedInfo2() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            ShowPixelInfo2(i);
        }
    }
}