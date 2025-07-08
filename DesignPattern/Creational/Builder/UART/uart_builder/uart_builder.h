#ifndef UART_BUILDER_H
#define UART_BUILDER_H

#include <stdio.h>
#include <stdlib.h>
#include "..\uart_config\uart_config.h"

#define DEFAULT_BAURATE 9600;
#define DEFAULT_DATABIT 8;
#define DEFAULT_STOPBIT 1;
#define DEFAULT_PARITY PARITY_NONE;

typedef struct UARTBuilder UARTBuilder;

struct UARTBuilder{
    UARTConfig config;
    UARTBuilder (*setBaudRate)(int baudRate);
    UARTBuilder (*setDataBits)(int dataBits);
    UARTBuilder (*setStopBits)(int stopBits);
    UARTBuilder (*setParity)(char parity);
    UARTConfig (*getConfig)(UARTBuilder builder);
};

UARTBuilder createUARTBuilder();

#endif
