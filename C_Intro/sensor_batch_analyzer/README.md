# 🌡️ Sensor Batch Analyzer – Embedded C

A C-based environmental data analyzer that processes a batch of temperature readings.  
Designed for embedded systems logic training, this tool reads 5 temperature inputs, validates them, and computes system diagnostics including:

- Min / Max temperature
- Average temperature
- Overheat and threshold alerts

---

## ✅ Features

- Input validation with negative value rejection
- Array-based data storage
- Real-time max and min detection
- Average calculation using `sum / N`
- Alert logic:
  - ⚠️ `> 35.0°C` triggers overheat warning
  - 🔥 `> 40.0°C` triggers critical alert

---

## 🧠 Concepts Practiced

| Concept             | Applied           |
|---------------------|-------------------|
| `for` loops         | ✅ Input & analysis  
| `float temps[5]`    | ✅ Array handling  
| Input validation    | ✅ `scanf()` + value check  
| Max/min logic       | ✅ System diagnostics  
| Embedded-style alerts | ✅ Multi-threshold detection  
| Output formatting   | ✅ `%.2f` for floats

---

## 💻 Sample Output

```bash
Enter Temperature 1: 25  
Enter Temperature 2: 30  
Enter Temperature 3: 45  
Enter Temperature 4: 39  
Enter Temperature 5: 31  

LOGGED TEMPERATURES  
Temperature 1: 25.00  
Temperature 2: 30.00  
Temperature 3: 45.00  
🔥 CRITICAL: Temp 3 exceeds 40°C!  
Temperature 4: 39.00  
⚠️  OVERHEAT WARNING: Temp 4 above 35°C  
Temperature 5: 31.00

--- SYSTEM REPORT ---
Average Temp: 34.00 °C  
Max Temp: 45.00 °C (Sensor 3)  
Min Temp: 25.00 °C (Sensor 1)

```
## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  