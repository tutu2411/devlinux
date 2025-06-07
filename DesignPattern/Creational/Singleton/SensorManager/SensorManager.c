#include <stdio.h>
#include <stdlib.h>
#include "SensorManager.h"

static SensorManager* sensorManagerInstance = NULL;

void collectDataImpl() {
    printf("Collecting data from sensors...\n");
}

void uploadToDatabaseImpl() {
    printf("Uploading data to the database...\n");
}

SensorManager* getSensorManager() 
{
    if (sensorManagerInstance == NULL) 
    {
        sensorManagerInstance = (SensorManager*)malloc(sizeof(SensorManager));
        if (sensorManagerInstance == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for SensorManager.\n");
            return NULL;
        }

        sensorManagerInstance->collectData = collectDataImpl;
        sensorManagerInstance->uploadToDatabase = uploadToDatabaseImpl;

        printf("SensorManager instance created successfully.\n");
    } 
    else 
    {
        printf("SensorManager instance already exists. Returning existing instance.\n");
    }

    return sensorManagerInstance;
}
