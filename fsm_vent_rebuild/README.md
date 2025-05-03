🌀 Auto-Ventilation System — FSM Controller (Arduino)
Author: Ahmet Emin Yakar
Role: Embedded Systems Engineer in Training
Date: May 2025
Repository Path: /Day15_FSM_Advanced/fsm_vent_rebuild.ino
Type: Real-time FSM-based actuator controller with sensor input, timed transitions, and EEPROM logging

🧠 Project Summary
This project implements a real-world finite state machine (FSM) on an Arduino Uno to control an auto-ventilation system based on temperature input. Using non-blocking millis() timing, the system manages state transitions, output activation (LED, buzzer), and persistent state logging with EEPROM. Designed to model an embedded control logic suitable for HVAC, IoT ventilation, or environmental chambers.

⚙️ System Overview
FSM States:
State	Behavior
IDLE	Wait for high temp; all outputs OFF
VENT_WAIT	LED blinks; timer starts; waits for confirm
VENT_ACTIVE	Buzzer ON; LED ON; logs cycle to EEPROM

Transitions:
From → To	Condition
IDLE → VENT_WAIT	temp ≥ 28°C
VENT_WAIT → IDLE	temp < 28°C
VENT_WAIT → ACTIVE	temp ≥ 28°C AND 10s passed
VENT_ACTIVE → IDLE	temp < 28°C or 30s timeout
(Any → IDLE)	global timeout (30s) — reset failsafe

🔌 Wiring Diagram
Component	Pin	Description
DHT11	D2	Temperature input sensor
LED	D9	Visual indicator output
Buzzer	D10	Audible alert output

DHT11 powered via 5V and GND

LED uses 220Ω resistor

Buzzer is active type (driven directly)

🧩 Core Features
⏱️ millis()-based timing (no delay())

🔁 Finite State Machine using enum + stateEntryTime

🔔 Outputs:

LED blinks during VENT_WAIT

LED solid ON during VENT_ACTIVE

Buzzer ON during VENT_ACTIVE

💾 EEPROM logging:

Each VENT_ACTIVE state increases cycle counter

Stored in EEPROM address 0

Printed at boot via Serial

🧪 Runtime Serial Output Example
yaml
Kopyala
Düzenle
TEMP : 27.4
TEMP : 28.1
transition : IDLE --> VENT_WAIT
...
transition : VENT_WAIT --> VENT_ACTIVE
VENT CYCLE COUNT: 4
transition : VENT_ACTIVE --> IDLE


📦 Future Upgrades
I2C LCD display: show temp, state, cycle count

Add button to clear EEPROM counter

ESP32 migration: Wi-Fi + mobile dashboard integration

Modular FSM structure with .h/.cpp files

Test harness using Python + UART monitoring

🎓 Engineering Highlights
Real-time FSM modeling with state-aware timing

EEPROM write safety via EEPROM.update()

Input validation with isnan()

Edge-triggered state logic with millis() delta

Strong separation of logic + output + timing layers

✅ Skills Demonstrated
Area	Technology	Skill
Embedded C++	Arduino	FSM logic, EEPROM, GPIO control
System Logic	FSM Design	State architecture + timing logic
Debug	Serial Output	State tracing and sensor logging
Persistence	EEPROM	Counter logging and recovery



## 👤 Author

Ahmet Emin Yakar  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)
