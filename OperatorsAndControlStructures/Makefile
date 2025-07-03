CC = gcc
CFLAGS = -Wall -g

SRCS = main.c LedDriver\led_driver.c

led_driver: $(SRCS)
	$(CC) $(CFLAGS) -o led_driver $(SRCS)

clean:
	rm -f led_driver

.PHONY: clean
