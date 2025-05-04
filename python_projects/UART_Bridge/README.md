# 🔄 UART Data Bridge – Arduino to Python

This project implements a **robust UART communication pipeline** between an Arduino and a Python script via serial. It simulates a real-world **sensor transmission system** with embedded checksum verification and structured data parsing.

---

## 📡 Overview

The system is designed to:
- Transmit temperature and humidity data over UART from Arduino.
- Include a **checksum** for integrity validation.
- Parse and verify this data on a Python script.
- Display results with live feedback in the terminal.

---

## 🔁 Data Format

The Arduino sends data in this format:

TEMP:24.3;HUM:61.7*187

Where:
- `*187` is the checksum → `sum(ascii of all characters before '*') % 256`
- The Python script verifies this value before processing the data.

---

## 🧩 Components

| Platform | File              | Purpose                         |
|----------|-------------------|---------------------------------|
| Arduino  | `uart_sender.ino` | Sends formatted UART sensor data every few seconds  
| Python   | `UART_Bridge.py`  | Listens, verifies, and displays parsed values

---

## 🧪 How It Works

### Arduino Side:
- Constructs `TEMP:xx.x;HUM:yy.y` strings.
- Calculates checksum and appends as `*checksum`.
- Sends over `Serial.print()`.

### Python Side:
- Reads serial data with `pyserial`.
- Splits the message and checks for validity.
- If checksum matches: extracts and prints sensor data.
- If corrupted: flags a warning.

---

## 🔧 Usage Instructions

### Arduino
1. Connect your Arduino via USB.
2. Upload `uart_sender.ino` using the Arduino IDE.

### Python

1. Install `pyserial`:

   pip install pyserial
    

Edit PORT in UART_Bridge.py to match your active serial port (e.g., COM3, /dev/ttyUSB0)

Run the script:

```bash
python UART_Bridge.py

```


✅ OK: Temp 24.3°C | Humidity 61.7%
❌ BAD CHECKSUM: TEMP:24.3;HUM:61.7*115
⚠️ Invalid format (no *): TEMP=22.1, HUM=60.5



🧠 Concepts Practiced
UART serial communication

Data formatting and integrity checks

ASCII-based checksum validation

Python string parsing and error handling

Real-world sensor transmission simulation


## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University 