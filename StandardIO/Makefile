CC = gcc
CFLAGS = -Wall -g

SRCS = main.c Logger\logger.c

logger: $(SRCS)
	$(CC) $(CFLAGS) -o logger $(SRCS)

clean:
	rm -f logger

.PHONY: clean
