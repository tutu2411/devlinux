#ifndef UART_CONFIG_H
#define UART_CONFIG_H

typedef enum Parity {
    PARITY_NONE,
    PARITY_EVEN,
    PARITY_ODD
} Parity;

typedef struct UARTConfig{
    int baudRate;
    int dataBits;
    int stopBits;
    Parity parity;
} UARTConfig;

#endif