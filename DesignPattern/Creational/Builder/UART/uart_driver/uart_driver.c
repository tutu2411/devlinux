#include <stdio.h>
#include "uart_driver.h"
#include "..\uart_config\uart_config.h"

void initUART(UARTConfig config) {
    printf("Initializing UART with:\n");
    printf("  Baud Rate: %d\n", config.baudRate);
    printf("  Data Bits: %d\n", config.dataBits);
    printf("  Stop Bits: %d\n", config.stopBits);
    printf("  Parity: %d\n", config.parity);
}
