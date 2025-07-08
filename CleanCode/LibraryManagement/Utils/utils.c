#include <stdio.h>
#include <string.h>
#include "utils.h"

void readLine(char* buffer, int length) {
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
}
