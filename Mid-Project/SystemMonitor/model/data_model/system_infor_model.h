#ifndef SYSTEM_INFOR_MODEL_H
#define SYSTEM_INFOR_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../cpu_infors/cpu_infors.h"

typedef struct {
    CpuInfo CpuInfo;
} SystemInfoModel;

void StartMonitor(SystemInfoModel *model);

#endif