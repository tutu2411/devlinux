#include "led_driver.h"

static uint32_t* ledBuffer = NULL;
static size_t ledCount = 0;

int ledInit(size_t numPixel) {

    if (numPixel == 0) return FAILED;

    ledBuffer = (uint32_t*)malloc(numPixel * sizeof(uint32_t));
    if (ledBuffer == NULL) return FAILED;

    ledCount = numPixel;
    printf("Create %d pixel success\n", numPixel);
    ledClear();
    printf("Clear led success\n");

    return SUUCCESS;
}

void ledSetPixelColor(size_t index, uint8_t red, uint8_t green, uint8_t blue) {
    
    if (index > ledCount) return;
    ledBuffer[index] = blue + (red << 8) + (green << 16);
}

void ledShutdown() {
    if (ledBuffer != NULL) {
        printf("memory has been free");
        free(ledBuffer);
        ledBuffer = NULL;
    }
}

void ledClear() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            ledBuffer[i] = 0;
        }
    }
}

void ledFill(uint8_t red, uint8_t green, uint8_t blue) {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            ledSetPixelColor(i, red, green, blue);
        }
    }
}

const uint32_t* getBuffer(){
    return ledBuffer;
}

size_t ledGetPixelCount() {
    return ledCount;
}

void showPixelInfo(size_t index) {

    if (index > ledCount) return;
    uint32_t pixel = ledBuffer[index];

    uint32_t blue = (pixel >> 0) & 0xFF;
    uint32_t red = (pixel >> 8) & 0xFF;
    uint32_t green = (pixel >> 16) & 0xFF;

    printf("PIXEL %d: GREEN %u RED %u BLUE %u\n",index, green, red, blue);
}

void showPixelInfo2(size_t index) {

    if (index > ledCount) return;
    uint32_t pixel = ledBuffer[index];

    printf("PIXEL %d: value 0x%08X\n",index, pixel);
}

void showLedInfo() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            showPixelInfo(i);
        }
    }
}

void showLedInfo2() {
    if (ledBuffer != NULL && ledCount != 0) {
        for (size_t i = 0; i < ledCount; i++) {
            showPixelInfo2(i);
        }
    }
}