# 🌬️ Auto Ventilation System (FSM-Controlled)

This project uses a DHT11 sensor and an LED to simulate a **temperature-triggered ventilation controller**. The system is governed by a **Finite State Machine (FSM)** and uses `millis()` for precise, non-blocking timing logic.

It demonstrates key embedded systems principles such as **state transitions**, **timing control without delay()**, and **sensor-based automation**.

---

## 🧠 FSM Design

| State         | Trigger                                     | LED Behavior   |
|---------------|---------------------------------------------|----------------|
| `IDLE`        | Temp < 28°C                                  | OFF            |
| `VENT_WAIT`   | Temp ≥ 28°C                                  | Slow blink     |
| `VENT_ACTIVE` | After 10 seconds in `VENT_WAIT`              | ON             |
| `→ IDLE`      | From any state if Temp drops below 26°C      | OFF, reset     |

The transition from `VENT_WAIT → VENT_ACTIVE` is handled using `millis()` timing logic to avoid blocking the processor.

---

## 🧰 Components

| Component    | Qty |
|--------------|-----|
| Arduino Uno  | 1   |
| DHT11 Sensor | 1   |
| LED          | 1   |
| Resistor (220Ω) | 1 |
| Jumper Wires | ~5  |
| Breadboard   | 1   |

---

## 💻 Code Highlights

- FSM built with `enum State { IDLE, VENT_WAIT, VENT_ACTIVE }`
- `millis()` used to track how long the system stays in `VENT_WAIT`
- `blinkLED()` function controls slow blinking behavior
- Serial Monitor logs state changes and sensor data

---

## 🧪 Sample Output (Serial Monitor)

Temperature: 29.5 °C | Humidity: 42.0 % 🔄 Transition: IDLE → VENT_WAIT

Temperature: 30.1 °C | Humidity: 43.5 %

Temperature: 30.2 °C | Humidity: 43.7 % 🔄 Transition: VENT_WAIT → VENT_ACTIVE

Temperature: 31.0 °C | Humidity: 44.0 %

Temperature: 25.0 °C | Humidity: 41.0 % 🔄 Transition: VENT_ACTIVE → IDLE


---
## 👤 Author

**Ahmet Emin Yakar**  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)  
💻 [GitHub](https://github.com/ahmeteminyakar)