#include <stdio.h>

int isAutoTogglePressed() {
    char c;
    printf("Press 'a' to toggle AUTO/MANUAL: ");
    c = getchar(); getchar();
    return c == 'a';
}

int isManualWaterPressed() {
    char c;
    printf("Press 'm' to manually water: ");
    c = getchar(); getchar();
    return c == 'm';
}
