#include <stdlib.h>
#include "uart_builder.h"

static UARTBuilder setBaudRate(UARTBuilder builder, int baudRate) {
    builder.config.baudRate = baudRate;
    return builder;
}

static UARTBuilder setDataBits(UARTBuilder builder, int dataBits) {
    builder.config.dataBits = dataBits;
    return builder;
}

static UARTBuilder setStopBits(UARTBuilder builder, int stopBits) {
    builder.config.stopBits = stopBits;
    return builder;
}

static UARTBuilder setParity(UARTBuilder builder, Parity parity) {
    builder.config.parity = parity;
    return builder;
}

static UARTConfig getConfig(UARTBuilder builder) {
    return builder.config;
}

UARTBuilder createUARTBuilder() {
    UARTBuilder builder;
    builder.config.baudRate = DEFAULT_BAURATE;
    builder.config.dataBits = DEFAULT_DATABIT;
    builder.config.stopBits = DEFAULT_STOPBIT;
    builder.config.parity = DEFAULT_PARITY;

    builder.setBaudRate = setBaudRate;
    builder.setDataBits = setDataBits;
    builder.setStopBits = setStopBits;
    builder.setParity = setParity;
    builder.getConfig = getConfig;
    return builder;
}
