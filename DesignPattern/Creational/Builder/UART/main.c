// main.c
#include "UARTBuilder.h"
#include "UARTDriver.h"

int main() {
    UARTBuilder builder = UARTBuilder_create();
    builder = UARTBuilder_setBaudRate(builder, 115200);
    builder = UARTBuilder_setDataBits(builder, 8);
    builder = UARTBuilder_setStopBits(builder, 1);
    builder = UARTBuilder_setParity(builder, 'N');

    UARTConfig config = UARTBuilder_build(builder);
    UART_init(config);


    UARTBuilder builder2 = UARTBuilder_create();
    // builder2 = UARTBuilder_setBaudRate(builder2, 9600);
    // builder2 = UARTBuilder_setDataBits(builder2, 8);
    // builder2 = UARTBuilder_setStopBits(builder2, 1);
    // builder2 = UARTBuilder_setParity(builder2, 'E');

    UARTConfig config2 = UARTBuilder_build(builder2);
    UART_init(config2);
    return 0;
}
