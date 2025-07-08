CC = gcc
CFLAGS = -Wall -g

SRCS = main.c Book\book.c Borrow\borrow.c User\user.c Utils\utils.c

led_driver: $(SRCS)
	$(CC) $(CFLAGS) -o led_driver $(SRCS)

clean:
	rm -f led_driver

.PHONY: clean
