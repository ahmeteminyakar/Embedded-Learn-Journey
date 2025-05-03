project:
  📛 name: "Auto-Ventilation FSM Controller"
  👤 author: "Ahmet Emin Yakar"
  🎓 role: "Embedded Systems Engineer in Training"
  🏫 education: "Gazi University – Electrical & Electronics Engineering"
  📅 date: "2025-05-03"
  🗂️ repo_path: "/Day15_FSM_Advanced/fsm_vent_rebuild.ino"
  🧠 description: >
    Real-time FSM controller using Arduino Uno and DHT11.
    Controls LED and Buzzer based on temperature thresholds,
    with non-blocking millis()-based timing and EEPROM-backed cycle logging.
    Designed for smart HVAC / IoT devices.

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
      🧭 type: "Input (Temp Sensor)"
    - 📦 name: "LED"
      🔗 pin: "D9"
      🧭 type: "Output (Blink/ON)"
    - 📦 name: "Buzzer"
      🔗 pin: "D10"
      🧭 type: "Output (Alert)"
  ⚡ wiring_notes: >
    - DHT11 connects to D2 with 5V and GND
    - LED uses 220Ω resistor on D9
    - Buzzer is active and driven from D10
    - All components share GND with the Arduino board

eeprom:
  💾 logging_enabled: true
  🎯 address_used: 0
  📦 stored_data: "VENT_ACTIVE cycle count (0–255)"
  ✍️ write_strategy: "EEPROM.update() only on state entry to minimize wear"
  🖨️ prints_at_startup: true

timing:
  ⏱️ millis_usage: true
  ⌛ timers:
    - name: "stateEntryTime"
      description: "Marks entry time for each state"
    - name: "threshold"
      value: "10s"
      use: "VENT_WAIT → VENT_ACTIVE"
    - name: "globalReset"
      value: "30s"
      use: "Failsafe reset to IDLE"

serial:
  💻 output_example: |
    TEMP : 27.4
    TEMP : 28.1
    transition : IDLE --> VENT_WAIT
    ...
    transition : VENT_WAIT --> VENT_ACTIVE
    VENT CYCLE COUNT: 4
    transition : VENT_ACTIVE --> IDLE

features:
  ✅ key_capabilities:
    - "⏱️ Non-blocking state logic with millis()"
    - "🧠 Real FSM: enum + state variable + timers"
    - "💾 EEPROM cycle logging with write protection"
    - "💡 LED blink in wait state"
    - "🔔 Buzzer in active state"
    - "⚠️ Global timeout failsafe"

skills_demonstrated:
  🧠 areas:
    - "FSM architecture design"
    - "Sensor integration with decision logic"
    - "millis() vs delay() timing mastery"
    - "EEPROM usage and flash wear management"
    - "Embedded-style Serial output for traceability"

files:
  📁 structure:
    - "fsm_vent_rebuild.ino"
    - "README.md"
    - "fsm_ascii_diagram.txt"
    - "fsm_wiring.fzz (optional)"

---

## 👤 Author

Ahmet Emin Yakar  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)