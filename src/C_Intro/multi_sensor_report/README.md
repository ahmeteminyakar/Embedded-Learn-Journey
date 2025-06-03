# 🔥 Multi-Sensor System Failure Detection – Embedded Logic in C

This C program simulates a real-time **environmental monitoring system** that classifies and evaluates readings from **three sensors**: Temperature, Humidity, and CO₂.  
It’s designed to mimic embedded firmware logic for multi-sensor safety systems in IoT or industrial applications.

---

## 🧠 What It Does

- Prompts the user to enter:
  - 🌡️ 3 temperature values
  - 💧 3 humidity values
  - 🫁 3 CO₂ values
- Classifies each reading based on safety thresholds
- Tracks how many values per sensor fall into a critical category
- If **2 or more sensors** exceed safety limits in at least **2 readings**, it triggers:
SYSTEM FAILURE: MULTIPLE CRITICAL CONDITIONS

---

## 🧪 Classification Logic

| Sensor Type   | Critical Condition             | Logic                          |
|---------------|--------------------------------|---------------------------------|
| Temperature   | `"OVERHEAT!"`                 | t > 30                         |
| Humidity      | `"HUMIDITY CRITICAL!"`        | h > 60                         |
| CO₂           | `"CO2 DANGER!"`               | c > 800                        |

---

## 🧩 Concepts Practiced

- `char*` functions for classification
- Arrays to hold multi-sensor input
- Loop-driven data analysis
- Condition tracking using counters
- `strcmp()` string comparison
- Final conditional system state evaluation

---

## 💻 Sample Output

Enter Temperature 1 : 41
Enter Humidity 1: 72
Enter CO2 1: 900
OVERHEAT!
HUMIDITY CRITICAL!
CO2 DANGER!
...
--- SYSTEM SUMMARY ---
🔥 Overheat Count: 2
💧 Humidity Critical Count: 2
🫁 CO2 Danger Count: 2

SYSTEM FAILURE: MULTIPLE CRITICAL CONDITIONS



---

## 👤 Author

Ahmet Emin Yakar  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)