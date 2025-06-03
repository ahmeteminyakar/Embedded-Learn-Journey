# Day 8 – Dual Button PWM LED FSM

This project demonstrates PWM control of **two LEDs** using a **Finite State Machine (FSM)** and **dual button input** on an Arduino Uno.

---

## 🧩 Components Used
- 1x Arduino Uno  
- 2x LEDs  
- 2x 220Ω resistors  
- 2x Push buttons  
- Jumper wires  
- Breadboard  

---

## ⚙️ Functional Logic

- **Two buttons** are used to change the brightness level of both LEDs:
  - **Button 1** → Increases brightness (`state++`)
  - **Button 2** → Decreases brightness (`state--`)
- FSM has **4 states** representing different brightness levels:
  1. `State 0` → Very Low  
  2. `State 1` → Low  
  3. `State 2` → Medium  
  4. `State 3` → High  
- Each button press triggers a state transition with debounce handled via delay.
- **Both LEDs mirror the current brightness level** using `analogWrite()` on PWM pins.

---

## 💾 Project Files
- `pwm_led_fsm2.ino` — Main Arduino code implementing FSM logic  
- `schematic.png` — Circuit schematic (if available)  

---

## 🧠 Skills Gained
- PWM control using `analogWrite()`  
- FSM logic using `switch-case`  
- Button debouncing with `INPUT_PULLUP` and `state tracking`  
- Multi-LED brightness control via synchronized states  
- Arduino pin configuration and structured code organization  

---

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  
