#ifndef UARTCONFIG_H
#define UARTCONFIG_H

typedef struct UARTConfig{
    int baudRate;
    int dataBits;
    int stopBits;
    char parity; // 'N' = None, 'E' = Even, 'O' = Odd
} UARTConfig;

#endif // UARTCONFIG_H