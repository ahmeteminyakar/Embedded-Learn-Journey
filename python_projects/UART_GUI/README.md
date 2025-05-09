# 🖥️ UART Packet Viewer – Tkinter + Simulated UART

This project builds a **live Python GUI** that simulates receiving and validating UART sensor packets using a structured format and checksum logic.  
It demonstrates a real-world embedded system interface for testing UART parsing, data validation, and GUI feedback — **no hardware required**.

---

## 📡 Overview

The system is designed to:
- Simulate UART packets like `"TEMP:24.3;HUM:50.2*210"`
- Use a **checksum** for packet integrity
- Parse and verify data in real-time
- Display valid/invalid results in a Python `tkinter` GUI

---

## 🔁 Data Format

Each UART line follows this format:

TEMP:24.3;HUM:61.7*187


Where:
- The payload (`TEMP:...;HUM:...`) contains float values
- `*187` is the checksum → calculated as `sum(ascii bytes before '*') % 256`
- A checksum mismatch flags error in the GUI

---

## 🧩 Components

| Component | File           | Purpose                         |
|-----------|----------------|---------------------------------|
| Python    | `uart_gui.py`  | Simulates UART reception and GUI display |
| Python    | `tkinter`      | GUI framework for visualization |
| Python    | `bytearray()`  | Converts strings to ASCII sums for checksum |

---

## 🧪 How It Works

### Simulated UART Logic:
- Generates realistic UART sensor strings
- Injects both valid and intentionally invalid packets
- Loops 1 message per second to simulate hardware feed

### GUI Behavior:
- ✅ Valid packets: displayed in green with payload
- ❌ Invalid checksum: red warning “MISMATCH!”
- ❌ Format errors: red warning “FORMAT ERROR”

---

## 🔧 Usage Instructions

1. Clone or copy the `uart_gui.py` file
2. Run the script in any Python 3 environment:

```bash
python uart_gui.py
The GUI will launch and show one packet per second with color-coded validation.

✅ Example Output
pgsql
Kopyala
Düzenle
TEMP:24.3;HUM:50.2           ← ✅ Green (valid)
MISMATCH!                    ← ❌ Red (bad checksum)
FORMAT ERROR                 ← ❌ Red (corrupt format)

```

🧠 Concepts Practiced
UART packet formatting and simulation

ASCII-based checksum verification (sum % 256)

Python GUI programming with tkinter

String parsing and error handling

Embedded-to-GUI system emulation

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University 