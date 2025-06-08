CC = gcc
CFLAGS = -Wall -g

SRCS = main.c SensorFactory.c TemperatureSensor.c HumiditySensor.c

sensor_app: $(SRCS)
	$(CC) $(CFLAGS) -o sensor_app $(SRCS)

clean:
	rm -f sensor_app

.PHONY: clean
