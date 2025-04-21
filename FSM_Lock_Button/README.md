# 🔐 Day 9 – Button Sequence Lock System (FSM Controlled)

This Arduino project simulates a **multi-step security lock system** using two buttons and an LED, governed by a **Finite State Machine (FSM)**.  
It mimics the logic behind digital keypad locks and stage-based embedded system security.

---

## 🧰 Components

| Component      | Qty |
|----------------|-----|
| Arduino Uno    | 1   |
| LED (Red/Green)| 1   |
| Push Button    | 2   |
| Resistor (220Ω)| 1   |
| Jumper Wires   | ~6  |
| Breadboard     | 1   |

---

## ⚙️ System Logic

- **State 0** (Locked): LED OFF
- **State 1**: Press **Button 1** → Advance
- **State 2**: Press **Button 2** → Advance
- **State 3**: Press **Button 1** → UNLOCK (LED ON 🔓)
- **Any wrong input resets FSM to State 0**

🧠 Built with a classic FSM (Finite State Machine) logic.

---

## 💻 Code File

- `fsm_lock_button.ino`

Key functions used:
- `digitalRead()`
- `pinMode()`
- `delay()`
- `analogWrite()` or `digitalWrite()`

---

## 🔌 Circuit Diagram

[Button 1] → D2 (INPUT_PULLUP)
[Button 2] → D3 (INPUT_PULLUP)
[LED (+)] → D9 (PWM)
[LED (–)] → GND via 220Ω

yaml
Kopyala
Düzenle

---

## 🧠 Concepts Practiced

- Finite State Machine (FSM)
- Input validation with sequence
- Debouncing with `delay()`
- State reset logic

---

## 📎 Folder Structure

📂 `Day9_ButtonSequenceLock/`  
├── `fsm_lock_button.ino`  
└── `README.md`  

---

## 👤 Author

**Ahmet Emin Yakar**  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)  
💻 [GitHub](https://github.com/ahmeteminyakar)

---