// UARTBuilder.c
#include "UARTBuilder.h"

UARTBuilder UARTBuilder_create() {
    UARTBuilder builder;
    builder.config.baudRate = 9600;   // default values
    builder.config.dataBits = 8;
    builder.config.stopBits = 1;
    builder.config.parity = 'N';
    return builder;
}

UARTBuilder UARTBuilder_setBaudRate(UARTBuilder builder, int baudRate) {
    builder.config.baudRate = baudRate;
    return builder;
}

UARTBuilder UARTBuilder_setDataBits(UARTBuilder builder, int dataBits) {
    builder.config.dataBits = dataBits;
    return builder;
}

UARTBuilder UARTBuilder_setStopBits(UARTBuilder builder, int stopBits) {
    builder.config.stopBits = stopBits;
    return builder;
}

UARTBuilder UARTBuilder_setParity(UARTBuilder builder, char parity) {
    builder.config.parity = parity;
    return builder;
}

UARTConfig UARTBuilder_build(UARTBuilder builder) {
    return builder.config;
}
