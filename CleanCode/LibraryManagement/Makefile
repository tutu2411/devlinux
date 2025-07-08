CC = gcc
CFLAGS = -Wall -g

SRCS = main.c Book\book.c Borrow\borrow.c User\user.c Utils\utils.c

libraryman: $(SRCS)
	$(CC) $(CFLAGS) -o libraryman $(SRCS)

clean:
	rm -f libraryman

.PHONY: clean
