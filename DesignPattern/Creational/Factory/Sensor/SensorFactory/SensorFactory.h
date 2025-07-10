// SensorFactory.h
#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include "Sensor.h"
#include "SensorType.h"

// Factory method to create sensor based on type
Sensor* createSensor(SensorType type);

#endif
