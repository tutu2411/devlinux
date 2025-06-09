#include <stdio.h>
#include <stdlib.h>
#include "UARTConfig.h"

// UARTBuilder.h
typedef struct UARTBuilder{
    UARTConfig config;
} UARTBuilder;

UARTBuilder UARTBuilder_create();
UARTBuilder UARTBuilder_setBaudRate(UARTBuilder builder, int baudRate);
UARTBuilder UARTBuilder_setDataBits(UARTBuilder builder, int dataBits);
UARTBuilder UARTBuilder_setStopBits(UARTBuilder builder, int stopBits);
UARTBuilder UARTBuilder_setParity(UARTBuilder builder, char parity);
UARTConfig UARTBuilder_build(UARTBuilder builder);
