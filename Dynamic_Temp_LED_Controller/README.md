# Smart Temperature Monitor (Arduino + DHT11 + PWM LED Control)

## 📜 Project Overview

This project implements a temperature-based LED control system using Arduino Uno and a DHT11 sensor.  
The LED brightness adjusts according to the input temperature value, and a warning is issued for high-temperature conditions.

The focus is to simulate a simple embedded control logic: dynamic output control based on environmental input.

---

## ⚙️ Technologies Used

- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- PWM (Pulse Width Modulation) for LED control
- Serial Communication (for user input simulation)

---

## 🔧 Hardware Setup

- Arduino Uno Board
- DHT11 Sensor
- LED + 220Ω Resistor
- Breadboard and Jumper Wires
- USB Connection for Serial Communication

---

## 📈 System Logic

| Temperature Range | LED Brightness | Delay Time | System Behavior |
|:------------------|:---------------|:-----------|:----------------|
| < 25°C | Low (PWM: 50) | 3000 ms | Normal |
| 25°C – 30°C | Medium (PWM: 155) | 2000 ms | Slightly Warm |
| > 30°C | High (PWM: 255) + Warning | 1000 ms | High Temperature |

---

## 🧠 Code Workflow

- **setup()**:  
  Initializes Serial communication, DHT sensor, and configures LED pin.

- **loop()**:  
  - Waits for temperature input from Serial Monitor.  
  - Validates the input value.  
  - Passes the temperature to `handleTemperature()`.

- **handleTemperature(temp)**:  
  - Adjusts LED brightness dynamically.  
  - Sets dynamic delay times.  
  - Prints status updates to Serial Monitor.

---

## 🖥️ Example Serial Monitor Output

```bash
Received Temperature: 24.0
LED set to LOW brightness
Waiting 3 seconds...

Received Temperature: 28.5
LED set to MEDIUM brightness
Waiting 2 seconds...

Received Temperature: 32.0
🔥 WARNING: High Temperature!
LED set to FULL brightness
Waiting 1 second...



🚀 How to Run
Upload the .ino file to your Arduino board.

Open Serial Monitor at 9600 baud rate.

Enter temperature values manually to simulate sensor input.

Observe LED brightness changes and system warnings.


📌 Future Improvements (Optional)
Automatic real-time DHT11 sensor readings

LCD Display integration for live data

WiFi integration using ESP32

Data logging to cloud or local storage

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  


