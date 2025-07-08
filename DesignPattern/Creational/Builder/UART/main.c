#include "uart_builder\uart_builder.h"
#include "uart_driver\uart_driver.h"

int main() {
    UARTBuilder builder = createUARTBuilder();
    builder.setBaudRate(115200)
            .setDataBits(8)
            .setStopBits(1)
            .setParity(PARITY_EVEN);
    
    initUART(builder.config);
    return 0;
}
