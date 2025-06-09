CC = gcc
CFLAGS = -Wall -g

SRCS = main.c UARTBuilder.c UARTDriver.c

UART_app: $(SRCS)
	$(CC) $(CFLAGS) -o UART_app $(SRCS)

clean:
	rm -f UART_app

.PHONY: clean
