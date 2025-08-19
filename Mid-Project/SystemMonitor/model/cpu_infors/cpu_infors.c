#include "cpu_infors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/// Read CPU usage from "/proc/stat"
void ReadCpuUsage(CpuInfo *info) {
    FILE *fp = fopen(PROC_STAT_PATH, "r");
    if (!fp) return;

    char line[256];
    unsigned long user, nice, system, idle, iowait, irq, softirq;
    int core = -1;
    info->core_count = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "cpu", 3) == 0) {
            if (line[3] == ' ') {
                // Tổng thể
                sscanf(line, "cpu  %lu %lu %lu %lu %lu %lu %lu",
                       &user, &nice, &system, &idle, &iowait, &irq, &softirq);
                unsigned long total = user+nice+system+idle+iowait+irq+softirq;
                static unsigned long prev_total=0, prev_idle=0;
                unsigned long totald = total - prev_total;
                unsigned long idled  = idle - prev_idle;
                info->total_usage = (totald - idled) * 100.0 / (totald ? totald : 1);
                prev_total = total;
                prev_idle = idle;
            } else {
                // Theo core
                core++;
                sscanf(line, "cpu%d %lu %lu %lu %lu %lu %lu %lu",
                       &core, &user, &nice, &system, &idle, &iowait, &irq, &softirq);
                unsigned long total = user+nice+system+idle+iowait+irq+softirq;
                static unsigned long prev_total[MAX_CORES] = {0}, prev_idle[MAX_CORES] = {0};
                unsigned long totald = total - prev_total[core];
                unsigned long idled  = idle - prev_idle[core];
                info->core_usage[core] = (totald - idled) * 100.0 / (totald ? totald : 1);
                prev_total[core] = total;
                prev_idle[core]  = idle;
                info->core_count = core + 1;
            }
        }
    }
    fclose(fp);
}

/// Đọc tần số CPU từ /proc/cpuinfo
void ReadCpuFrequency(CpuInfo *info) {
    FILE *fp = fopen(PROC_CPUINFO_PATH, "r");
    if (!fp) return;

    char line[256];
    int core = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "cpu MHz", 7) == 0 && core < MAX_CORES) {
            float mhz;
            sscanf(line, "cpu MHz : %f", &mhz);
            info->freq_khz[core++] = (long)(mhz * 1000);
        }
    }
    fclose(fp);
}

/// Đọc nhiệt độ CPU từ hwmon
void ReadCpuTemperature(CpuInfo *info) {
    FILE *fp = fopen(SYS_THERMAL_PATH, "r");
    if (!fp) {
        info->temperature = -1;
        return;
    }
    int temp;
    fscanf(fp, "%d", &temp);
    fclose(fp);
    info->temperature = temp / 1000.0; // °C
}

/// Đọc top 5 tiến trình dùng CPU cao nhất (sử dụng ps)
void ReadTopProcesses(CpuInfo *info) {
    FILE *fp = popen(CMD_TOP_PROCESSES, "r");
    if (!fp) return;

    char name[MAX_PROC_NAME];
    float usage;
    int i = 0;
    char line[256];
    fgets(line, sizeof(line), fp); // bỏ dòng tiêu đề
    while (fgets(line, sizeof(line), fp) && i < TOP_PROC) {
        if (sscanf(line, "%s %f", name, &usage) == 2) {
            strncpy(info->top_processes[i], name, MAX_PROC_NAME);
            info->top_proc_usage[i] = usage;
            i++;
        }
    }
    pclose(fp);
}
