CC = gcc
CFLAGS = -Wall -g

SRCS = main.c facade\smart_home_facade.c HVAC\hvac_system.c Lighting\lighting_system.c Security\sercurity_system.c

smart_home_app: $(SRCS)
	$(CC) $(CFLAGS) -o smart_home_app $(SRCS)

clean:
	rm -f smart_home_app

.PHONY: clean
