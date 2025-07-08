CC = gcc
CFLAGS = -Wall -g

SRCS = main.c uart_builder\uart_builder.c uart_driver\uart_driver.c

UART_app: $(SRCS)
	$(CC) $(CFLAGS) -o UART_app $(SRCS)

clean:
	rm -f UART_app

.PHONY: clean
