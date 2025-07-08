#include "Logger\logger.h"

int main() {
    loggerInit(LOG_INFO, "log.txt");

    logMessage(LOG_DEBUG, "This is a debug message.");
    logMessage(LOG_INFO, "Program started.");
    logMessage(LOG_WARNING, "Low disk space.");
    logMessage(LOG_ERROR, "Failed to open file.");
    logMessage(LOG_EMERGENCY, "System crash imminent!");

    loggerSetLevel(LOG_ERROR);
    logMessage(LOG_INFO, "This message should be skipped.");
    logMessage(LOG_CRITICAL, "Critical failure!");

    loggerClose();
    return 0;
}
