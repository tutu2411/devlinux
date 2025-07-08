#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
    LOG_EMERGENCY = 0,  // System is unusable
    LOG_ALERT,          // Immediate action required
    LOG_CRITICAL,       // Critical condition
    LOG_ERROR,          // General error
    LOG_WARNING,        // Warning
    LOG_NOTICE,         // Important notice (not an error)
    LOG_INFO,           // Informational message
    LOG_DEBUG           // Debug-level message
} LogLevel;


void loggerInit(LogLevel level, const char *filePath);
void loggerLog(LogLevel level, const char *file, int line, const char *format, ...);
void loggerClose();
void loggerSetLevel(LogLevel level);


#define logMessage(level, fmt, ...) \
    loggerLog(level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif
