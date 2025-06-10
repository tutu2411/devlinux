CC = gcc
CFLAGS = -Wall -g

SRCS = main.c Sensor.c MobileApp.c AlarmSystem.c LightingSystem.c

IOT_app: $(SRCS)
	$(CC) $(CFLAGS) -o IOT_app $(SRCS)

clean:
	rm -f IOT_app

.PHONY: clean
