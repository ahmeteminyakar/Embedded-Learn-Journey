# 🖥️ UART FSM Packet Simulator (Python + Tkinter)

This project simulates a **UART packet receiver** with a real-time **Finite State Machine (FSM)** implemented using Python and Tkinter.  
It visually displays the state transitions as it validates incoming UART-style messages.

---

## 🚦 FSM Structure

```python
class FSMState(Enum):
    WAIT = 0
    VALID = 1
    ERROR = 2
```

Each state is reflected in the GUI as the system:
- Waits for the next packet
- Validates checksum
- Detects errors in structure or data

---

## 📡 UART Packet Format

The simulated data follows this format:

```
TEMP:24.2;HUM:55.0*123
```

- The checksum (`*123`) is calculated as:  
  `sum(bytearray(payload.encode())) % 256`

---

## 💻 GUI Behavior

| FSM State | Description                     | Label Output                         | Color   |
|-----------|---------------------------------|--------------------------------------|---------|
| WAIT      | Before receiving a packet       | `[WAIT] Waiting...`                  | Black   |
| VALID     | Valid packet received           | `[VALID] TEMP:xx.x;HUM:yy.y`         | Green   |
| ERROR     | Checksum or format invalid      | `[ERROR] MISMATCH!` or `FORMAT ERROR`| Red / Orange |

---

## 🧪 Example Output

```
[WAIT] Waiting...
[VALID] TEMP:24.2;HUM:55.0
[WAIT] Waiting...
[VALID] TEMP:38.0;HUM:34.0
[WAIT] Waiting...
[VALID] TEMP:29.8;HUM:43.6
[WAIT] Waiting...
[ERROR] MISMATCH!
```

---

## 🧩 Concepts Practiced

- UART packet simulation and parsing  
- FSM implementation using Python `Enum`  
- Real-time UI feedback with `tkinter`  
- ASCII-based checksum validation  
- Embedded system behavior emulation in software

---

## ▶️ Run Instructions

1. Make sure Python 3 is installed.
2. Run the script:

```bash
python uart_gui_fsm.py
```

No external dependencies are needed beyond `tkinter` (which is built into Python).

---

## 🔗 Author

**Ahmet Emin Yakar**  
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Gazi University – Electrical & Electronics Engineering
