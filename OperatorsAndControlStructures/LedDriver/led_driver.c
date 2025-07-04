#include "led_driver.h"

static uint32_t* LedBuffer = NULL;
static size_t LedCount = 0;

int LedInit(size_t NumPixel) {

    if (NumPixel == 0) return FAILED;

    LedBuffer = (uint32_t*)malloc(NumPixel * sizeof(uint32_t));
    if (LedBuffer == NULL) return FAILED;

    LedCount = NumPixel;
    printf("Create %d pixel success\n", NumPixel);
    LedClear();
    printf("Clear led success\n");

    return SUUCCESS;
}

void LedSetPixelColor(size_t Index, uint8_t Red, uint8_t Green, uint8_t Blue) {
    
    if (Index > LedCount) return;
    LedBuffer[Index] = Blue + (Red << 8) + (Green << 16);
}

void LedShutdown() {
    if (LedBuffer != NULL) {
        printf("memory has been free");
        free(LedBuffer);
        LedBuffer = NULL;
    }
}

void LedClear() {
    if (LedBuffer != NULL && LedCount != 0) {
        for (size_t i = 0; i < LedCount; i++) {
            LedBuffer[i] = 0;
        }
    }
}

void LedFill(uint8_t red, uint8_t green, uint8_t blue) {
    if (LedBuffer != NULL && LedCount != 0) {
        for (size_t i = 0; i < LedCount; i++) {
            LedSetPixelColor(i, red, green, blue);
        }
    }
}

const uint32_t* GetBuffer(){
    return LedBuffer;
}

size_t LedGetPixelCount() {
    return LedCount;
}

void ShowPixelInfo(size_t index) {

    if (index > LedCount) return;
    uint32_t Pixel = LedBuffer[index];

    uint32_t Blue = (Pixel >> 0) & 0xFF;
    uint32_t Red = (Pixel >> 8) & 0xFF;
    uint32_t Green = (Pixel >> 16) & 0xFF;

    printf("PIXEL %d: GREEN %u RED %u BLUE %u\n",index, Green, Red, Blue);
}

void ShowPixelInHexa(size_t PixelIndex) {

    if (PixelIndex > LedCount) return;
    uint32_t Pixel = LedBuffer[PixelIndex];

    printf("PIXEL %d: value 0x%08X\n",PixelIndex, Pixel);
}

void ShowLedInfo() {
    if (LedBuffer != NULL && LedCount != 0) {
        for (size_t i = 0; i < LedCount; i++) {
            ShowPixelInfo(i);
        }
    }
}

void ShowLedInfoInHexa() {
    if (LedBuffer != NULL && LedCount != 0) {
        for (size_t i = 0; i < LedCount; i++) {
            ShowPixelInHexa(i);
        }
    }
}