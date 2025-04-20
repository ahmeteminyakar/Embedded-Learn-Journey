# Day 8 – Dual Button PWM LED FSM

This project uses two buttons to control two LEDs via PWM using a Finite State Machine (FSM) structure on Arduino Uno.

---

## 🧩 Components

- 1x Arduino Uno
- 2x LEDs
- 2x 220Ω Resistors
- 2x Push Buttons
- Jumper Wires
- Breadboard

---

## ⚙️ Logic

- Two buttons:
  - **Button 1:** increases brightness
  - **Button 2:** decreases brightness
- FSM has 4 states:
  - 0 → Very Low Brightness
  - 1 → Low
  - 2 → Medium
  - 3 → High
- Debounce is handled with simple delay.
- Both LEDs mirror the brightness level.

---

## 💾 Files

- `pwm_led_fsm2.ino` — full source code
- `schematic.png` — circuit diagram (if available)

---

## 🧠 Skills Practiced

- PWM control using `analogWrite()`
- FSM logic with `switch-case`
- Button input with `INPUT_PULLUP`
- Debounce using state tracking

---

🔗 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)
