#include "system_infor_controller.h"

void StartController() {
    SystemInfoModel* model;
    model = malloc(sizeof(SystemInfoModel));


    while (1)
    {
        ReadCpuUsage(&model->CpuInfo);
        ReadCpuFrequency(&model->CpuInfo);
        ReadCpuTemperature(&model->CpuInfo);
        ReadTopProcesses(&model->CpuInfo);


        DisplayCpuInfo(&model->CpuInfo);

        sleep(2);
    }
}