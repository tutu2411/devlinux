CC = gcc
CFLAGS = -Wall -g

SRCS = main.c facade\smart_home_facade.c HVAC\hvac_system.c Lighting\lighting_system.c Security\sercurity_system.c

facade_app: $(SRCS)
	$(CC) $(CFLAGS) -o facade_app $(SRCS)

clean:
	rm -f facade_app

.PHONY: clean
