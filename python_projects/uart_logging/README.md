# 📝 CO₂ Data Logger – Python CSV Logger

This project logs simulated or real CO₂ sensor readings with timestamps into a `.csv` file using Python. It is structured as a lightweight data logging utility, ideal for integrating with UART or MQTT-based sensor systems.

---

## 📄 What It Does

- Captures a CO₂ value (simulated or received)
- Appends it to a CSV log file with the current timestamp
- Automatically creates `co2_log.csv` if not present
- Designed to be used in **sensor-to-PC UART bridges**, **MQTT collectors**, or standalone batch scripts

---

## 💻 Files

| File             | Description                             |
|------------------|-----------------------------------------|
| `uart_logging.py`| Python script for CO₂ data logging      |
| `co2_log.csv`    | Auto-generated log of timestamped values|

---

## 🧪 Example Log Output

14:55:10,805.5
14:57:44,793.2
15:01:18,812.0


---

## 🧠 Concepts Demonstrated

- Use of `datetime` for time-stamping
- Writing structured data to `.csv` files
- `with open()` safe file handling
- Logging system separation from UART parsing

---

## 🚀 Usage Instructions

1. Make sure Python 3 is installed
2. Run the logger:
   ```bash
   python uart_logging.py



View output in co2_log.csv

📝 You can adapt this script to read from serial (pyserial) or MQTT handlers.

🔁 Future Extensions
Real-time logging from Arduino/ESP32 via UART

Integration with Python GUI or live plotting

File rotation for long-term logging   


## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University 