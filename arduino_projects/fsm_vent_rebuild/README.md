# 🌬️ FSM Ventilation Control System – Arduino + DHT11

This project implements a Finite State Machine (FSM) to control a ventilation system based on temperature readings from a DHT11 sensor. It uses non-blocking logic (`millis()`) to manage state transitions, a blinking LED indicator, and an audible buzzer alert when critical conditions are met.

---

## 🧠 System Overview

The system cycles through three operational states based on real-time temperature values:

| State         | Condition                               | Action                       |
|---------------|------------------------------------------|------------------------------|
| `IDLE`        | Temperature < 28°C                       | LED OFF, Buzzer OFF          |
| `VENT_WAIT`   | Temp ≥ 28°C (entry), Temp < 26 = reset   | LED blinks every 200ms       |
| `VENT_ACTIVE` | Temp ≥ 28°C for 10s continuously         | LED ON, Buzzer ON            |

All transitions are time- and condition-based using `millis()`.

---

## ⚙️ Components

| Component   | Qty | Pin     |
|-------------|-----|----------|
| DHT11 Sensor| 1   | D2       |
| LED         | 1   | D9       |
| Buzzer      | 1   | D10      |
| Arduino UNO | 1   | —        |
| Resistors   | 2   | For LED/Buzzer if needed |

---



## 🕒 Timing Behavior

- `millis()` tracks elapsed time since entry to `VENT_WAIT`
- If 10s pass and temp ≥ 28°C → activate ventilation
- LED blinks in `VENT_WAIT` to show system is "warming up"
- Buzzer is active only in `VENT_ACTIVE`

---

## 💻 File Description

| File Name            | Description                           |
|----------------------|----------------------------------------|
| `fsm_vent_rebuild.ino` | Main Arduino source code implementing FSM  
| `README.md`          | Project logic, wiring, and usage doc  |

---

## 🧪 How to Use

1. Wire components as listed above
2. Upload the sketch to your Arduino UNO
3. Open Serial Monitor @9600 baud to monitor status
4. Increase temperature near DHT11 to trigger transitions

---

## 👤 Author

**Ahmet Emin Yakar**  
🎓 Electrical & Electronics Engineering – Gazi University  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)  
💻 [GitHub](https://github.com/ahmeteminyakar)

---

## 📦 Repository

Part of the [Embedded Systems Portfolio](https://github.com/ahmeteminyakar/Embedded-Learn-Journey), demonstrating FSM design, non-blocking Arduino control, and environmental automation logic.