#ifndef CPU_INFORS_H
#define CPU_INFORS_H

#define MAX_CORES 64
#define MAX_PROC_NAME 256
#define TOP_PROC 5

// Linux system information path
#define PROC_STAT_PATH        "/proc/stat"
#define PROC_CPUINFO_PATH     "/proc/cpuinfo"
#define SYS_THERMAL_PATH      "/sys/class/thermal/thermal_zone0/temp"
#define CMD_TOP_PROCESSES     "ps -eo comm,%cpu --sort=-%cpu | head -n 6"

typedef struct {
    float total_usage;
    float core_usage[MAX_CORES];
    int core_count;
    long freq_khz[MAX_CORES];
    float temperature;
    char top_processes[TOP_PROC][MAX_PROC_NAME];
    float top_proc_usage[TOP_PROC];
} CpuInfo;

// API
void ReadCpuUsage(CpuInfo *info);
void ReadCpuFrequency(CpuInfo *info);
void ReadCpuTemperature(CpuInfo *info);
void ReadTopProcesses(CpuInfo *info);
#endif
