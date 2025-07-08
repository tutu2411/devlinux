#include "logger.h"
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

static FILE *logFile = NULL;
static LogLevel currentLevel = LOG_DEBUG;

static const char *levelToString(LogLevel level) {
    const char *levels[] = {
        "EMERGENCY", "ALERT", "CRITICAL", "ERROR",
        "WARNING", "NOTICE", "INFO", "DEBUG"
    };
    return (level >= 0 && level <= LOG_DEBUG) ? levels[level] : "UNKNOWN";
}

void loggerInit(LogLevel level, const char *filePath) {
    currentLevel = level;
    if (filePath != NULL) {
        logFile = fopen(filePath, "a");
        if (!logFile) {
            fprintf(stderr, "Failed to open log file: %s\n", filePath);
        }
    }
}

void loggerSetLevel(LogLevel level) {
    currentLevel = level;
}

void loggerLog(LogLevel level, const char *file, int line, const char *format, ...) {
    if (level > currentLevel) return;

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char timeBuffer[20];
    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", t);

    char messageBuffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
    va_end(args);

    char finalBuffer[1200];
    snprintf(finalBuffer, sizeof(finalBuffer), "[%s] [%s] [%s:%d] - %s\n",
             timeBuffer, levelToString(level), file, line, messageBuffer);

    FILE *stream = (level <= LOG_ERROR) ? stderr : stdout;
    fprintf(stream, "%s", finalBuffer);
    fflush(stream);

    if (logFile) {
        fprintf(logFile, "%s", finalBuffer);
        fflush(logFile);
    }
}

void loggerClose() {
    if (logFile) {
        fclose(logFile);
        logFile = NULL;
    }
}
