# SmartHome Facade – Exercise 2: Simplify Smart Home Control with the Facade Pattern

## 💡 Problem Description

You are developing a central controller (Hub) for a smart home system. The hub is responsible for managing and coordinating multiple subsystems, including:

- 🔆 **Lighting System**: Controls turning lights on/off and adjusting brightness in rooms.
- 🛡️ **Security System**: Activates/deactivates alarms, monitors door and motion sensors.
- ❄️ **HVAC System**: Adjusts temperature and operational mode (cooling/heating).

### ❗ The problem:
1. Each subsystem has its own complex API for configuration and control.
2. The application layer must directly interact with all subsystem APIs, making the code messy and hard to maintain.
3. Any change in a subsystem (e.g., new lighting module with a different API) requires changes across many parts of the application.

---

## ✅ Objective

Use the **Facade Pattern** to:
- **Simplify** the interface for smart home control.
- **Hide the complexity** of individual subsystems from the application layer.
- **Loosely couple** the application from subsystem implementations.
- Provide high-level APIs to trigger common scenarios like:
  - `activateMorningRoutine()`
  - `activateAwayMode()`
  - `setMovieNightScene()`

---

## 🏗️ Project Structure

Facade/
├── main.c # Entry point, uses SmartHomeFacade
├── SmartHomeFacade.h / .c # Facade class controlling all subsystems
├── Lighting/lighting_system.h / .c # Lighting system implementation
├── Security/security_system.h / .c # Security system implementation
├── HVAC/hvac_system.h / .c # HVAC system implementation
└── README.md # This documentation

---

## 🔧 Build & Run

### Compile (GCC)

```bash
make
./smart_home_app
```
---

## 📌 Design Notes
- **SmartHomeFacade** completely abstracts away lighting, security, and HVAC logic.

- The application layer does not directly call subsystem APIs.

- Easy to maintain: adding a new system only requires changes inside the Facade, not in main.

---

## 🚀 Possible Extensions
- Add more systems: audio, blinds, garden sprinklers, etc.

- Allow user-defined routines via config files.

- Make the system event-driven or reactive to real-time sensors.

- Add more hvac mode such as: FAN_ONLY, TURN_OFF, AUTO,...

---