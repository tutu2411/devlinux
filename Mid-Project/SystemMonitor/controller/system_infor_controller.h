#ifndef SYSTEM_INFOR_CONTROLLER_H
#define SYSTEM_INFOR_CONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../model/data_model/system_infor_model.h"
#include "../view/system_infor_view.h"
#include <unistd.h>


typedef struct {
    SystemInfoModel data;
} SystemInfoController;

void StartController();

#endif