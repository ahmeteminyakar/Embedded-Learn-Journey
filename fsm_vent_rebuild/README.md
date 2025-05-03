project:
  📛 name: "Auto-Ventilation FSM Controller"
  👤 author: "Ahmet Emin Yakar"
  🎓 role: "Embedded Systems Engineer in Training"
  📅 date: "2025-05-03"
  🗂️ repo_path: "/Day15_FSM_Advanced/fsm_vent_rebuild.ino"
  🧠 description: >
    Real-time FSM controller using Arduino Uno and DHT11.
    Controls LED and Buzzer based on temperature thresholds,
    with non-blocking millis()-based timing and EEPROM-backed cycle logging.

fsm:
  🔁 states:
    - "IDLE"
    - "VENT_WAIT"
    - "VENT_ACTIVE"
  🔀 transitions:
    - from: "IDLE"
      to: "VENT_WAIT"
      condition: "🌡️ temp ≥ 28°C"
    - from: "VENT_WAIT"
      to: "IDLE"
      condition: "🌡️ temp < 28°C"
    - from: "VENT_WAIT"
      to: "VENT_ACTIVE"
      condition: "🌡️ temp ≥ 28°C AND ⏱️ 10s passed"
    - from: "VENT_ACTIVE"
      to: "IDLE"
      condition: "🌡️ temp < 28°C OR ⏱️ 30s timeout"
    - from: "*"
      to: "IDLE"
      condition: "⚠️ Global timeout (30s)"

hardware:
  🔌 components:
    - 📦 name: "DHT11"
      🔗 pin: "D2"
      🧭 type: "Input (Temperature Sensor)"
    - 📦 name: "LED"
      🔗 pin: "D9"
      🧭 type: "Output (Blink/ON)"
    - 📦 name: "Buzzer"
      🔗 pin: "D10"
      🧭 type: "Output (Alert)"
  💡 wiring_notes: >
    - DHT11 connected to D2 (with 5V and GND).
    - LED on D9 with 220Ω resistor.
    - Active Buzzer connected directly to D10.
    - All components use shared GND.

features:
  🎯 highlights:
    - "⚙️ Finite State Machine (FSM) structure"
    - "⏱️ Non-blocking timing using millis()"
    - "💾 EEPROM cycle logging (VENT_ACTIVE count)"
    - "💡 LED blinking logic in VENT_WAIT"
    - "🔔 Buzzer ON in VENT_ACTIVE"
    - "🧠 `isnan()` validation for sensor reads"
    - "♻️ Global timeout failsafe after 30s"

serial_output_example: |
  TEMP : 27.4
  TEMP : 28.1
  transition : IDLE --> VENT_WAIT
  ...
  transition : VENT_WAIT --> VENT_ACTIVE
  VENT CYCLE COUNT: 4
  transition : VENT_ACTIVE --> IDLE

future_upgrades:
  🚀 roadmap:
    - "🖥️ Add I2C LCD to display state + temp + cycles"
    - "🧼 EEPROM reset button"
    - "📡 ESP32 migration: Wi-Fi dashboard"
    - "🧱 Modular FSM structure with handlers"
    - "🧪 Python test harness via UART"

skills_demonstrated:
  📌 areas:
    - "Embedded C++ with Arduino"
    - "Real-world FSM design"
    - "millis() timing architecture"
    - "EEPROM safety with update()"
    - "Sensor validation + event logging"
    - "Serial debug-based system trace"


## 👤 Author

Ahmet Emin Yakar  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)