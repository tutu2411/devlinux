
#include "system_infor_view.h"

void DisplayCpuInfo(CpuInfo *cpu) {
    printf("=== CPU INFO ===\n");
    printf("CPU pervent usage: %.1f \n", cpu->total_usage);
    printf("Frequency: %.2ld KHz\n", cpu->freq_khz[0]);
    printf("Temperature: %.1f °C\n", cpu->temperature);
    printf("================\n");
}
