#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

typedef struct SecuritySystem {
    void (*activateAlarm)(void);
    void (*deactivateAlarm)(void);
    void (*monitorSensor)(void);
} SecuritySystem;

SecuritySystem* createSecuritySystem();

#endif