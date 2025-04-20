# Day 8 – Dual Button PWM FSM

This project demonstrates an advanced Finite State Machine (FSM) system that uses **two push buttons** to control the **brightness of two LEDs** via **PWM** on an Arduino.

---

## 🔧 Components Used

- Arduino Uno  
- 2x LEDs  
- 2x 220Ω Resistors  
- 2x Push Buttons  
- Breadboard  
- Jumper Wires  

---

## 🧠 Project Logic

- Two buttons are used to **navigate forward and backward** through brightness states.
- Each state controls the **PWM output** of two LEDs simultaneously.
- FSM is implemented using `switch-case`.
- Debounce is handled with a simple delay.
- Inputs are handled using `INPUT_PULLUP`, meaning active LOW logic.

---

## ⚙️ System Behavior

| Button      | Action                    |
|-------------|---------------------------|
| Button 1    | Next brightness level     |
| Button 2    | Previous brightness level |

| FSM State | Brightness (PWM) |
|-----------|------------------|
| 0         | 10 (Low)         |
| 1         | 50               |
| 2         | 150              |
| 3         | 255 (Max)        |

---

## 🖥️ Pin Configuration

| Component   | Arduino Pin |
|-------------|-------------|
| LED 1       | D9 (PWM)    |
| LED 2       | D10 (PWM)   |
| Button 1    | D2          |
| Button 2    | D3          |

> Note: Buttons connected to GND; internal pull-up resistors are enabled.

---

## 💾 Code File

📄 `DualButton_PWM_FSM.ino`  
Located in:  
📁 `/Day8_DualButton_PWM_FSM/`

---

## 🧠 Concepts Practiced

- Finite State Machine (FSM)  
- Dual button control  
- PWM output with `analogWrite()`  
- Edge detection (rising-to-falling transition)  
- Internal pull-up resistor usage  

---

## 📸 Circuit Schematic

🖼️ `schematic.png` *(to be added)*  
Includes 2 buttons, 2 LEDs, common GND, and PWM outputs.

---

## 🎓 Part of: `Embedded-Learn-Journey (Day 8)`

📅 April 2025  
Built with ❤️ by [Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
GitHub Repo: [github.com/ahmeteminyakar/Embedded-Learn-Journey](https://github.com/ahmeteminyakar/Embedded-Learn-Journey)
## 📝 Overview

This project implements a dual button control system using a finite state machine (FSM) to manage the brightness of two LEDs via PWM signals. The system utilizes edge detection to respond to button presses, demonstrating effective use of internal pull-up resistors for reliable button state management.