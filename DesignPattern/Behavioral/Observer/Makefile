CC = gcc
CFLAGS = -Wall -g

SRCS = main.c \Sensor\Sensor.c \Subscriber\MobileApp.c \Subscriber\AlarmSystem.c \Subscriber\LightingSystem.c

IOT_app: $(SRCS)
	$(CC) $(CFLAGS) -o IOT_app $(SRCS)

clean:
	rm -f IOT_app

.PHONY: clean
