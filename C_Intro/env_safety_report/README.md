# 🌡️ Environmental Safety Report System (C Language)

This C program simulates a basic embedded sensor analysis system that collects **5 temperature readings**, classifies them using a function, and provides a **summary report** with safety insights.

Designed to mimic real-world logic used in embedded systems and IoT monitoring applications.

---

## 🧩 Key Features

- Accepts 5 temperature inputs via `scanf()`
- Classifies each value as:
  - ❄️ **FREEZING** (t < 0°C)
  - 🌤 **NORMAL TEMPERATURE** (0°C ≤ t ≤ 30°C)
  - 🔥 **OVERHEAT!** (t > 30°C)
- Calculates:
  - 🔁 **Average temperature**
  - 📈 **Maximum temperature**
- Detects:
  - ⚠️ **Unstable conditions** if 2 or more temperatures exceed 30°C

---

## 🧠 Concepts Practiced

- `char*` return functions  
- Input validation with `scanf()`  
- String comparison with `strcmp()`  
- Looping through arrays  
- Conditional branching (`if-else if-else`)  
- Floating point math and precision output  
- Max tracking and average calculations

---

## 💻 Sample Output

Enter Temperature 1: 25
🌤 NORMAL TEMPERATURE
Enter Temperature 2: 42
🔥 OVERHEAT!
Enter Temperature 3: 38
🔥 OVERHEAT!
Enter Temperature 4: -5
❄️ FREEZING
Enter Temperature 5: 28
🌤 NORMAL TEMPERATURE

Average Temperature : 25.60
Max Temperature : 42.00
UNSTABLE ENVIRONMENT!


---

## 👤 Author

Ahmet Emin Yakar  
🎓 Gazi University – Electrical & Electronics Engineering  
🔗 [LinkedIn](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/)