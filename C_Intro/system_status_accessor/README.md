🚨 System Status Assessor – C Project

A multi-sensor logic evaluation system written in C, designed to simulate an embedded-style decision engine for environmental control.

This system reads **temperature**, **humidity**, and **CO2** levels from user input and classifies each using modular logic functions. If two or more values exceed safety thresholds, a critical system alert is raised.

---

🧰 Sensors Simulated:
- Temperature (float)
- Humidity (float)
- CO2 concentration (float)

---

⚙️ System Logic

| Parameter   | Normal Threshold | Critical If  |
|-------------|------------------|--------------|
| Temperature | ≤ 30             | > 30         |
| Humidity    | ≤ 60             | > 60         |
| CO2         | ≤ 800            | > 800        |

Each sensor is evaluated by its own function:
- `char* classifyTemp(float)`
- `char* classifyHumidity(float)`
- `char* classifyCO2(float)`

---

🛡️ Alert Logic

If **2 or more** sensors return `"Critical"`, the system triggers:

⚠️ SYSTEM ALERT: At least two sensors are in critical condition!

yaml
Kopyala
Düzenle

---

💻 Sample Output

```bash
Enter the temperature: 32  
Enter the humidity: 45  
Enter the CO2: 950  

Critical Temperature  
Normal Humidity  
Critical CO2  
⚠️ SYSTEM ALERT: At least two sensors are in critical condition!
```

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  