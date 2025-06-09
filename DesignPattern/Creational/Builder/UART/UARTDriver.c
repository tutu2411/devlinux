// UARTDriver.c
#include <stdio.h>
#include "UARTDriver.h"

void UART_init(UARTConfig config) {
    printf("Initializing UART with:\n");
    printf("  Baud Rate: %d\n", config.baudRate);
    printf("  Data Bits: %d\n", config.dataBits);
    printf("  Stop Bits: %d\n", config.stopBits);
    printf("  Parity: %c\n", config.parity);
}
