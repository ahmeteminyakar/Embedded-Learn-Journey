🔰 Day 13 – Temperature Classifier System (C Language)

This C project simulates a basic system that reads a user-input temperature and classifies it into meaningful status messages using `if-else` logic and modular functions.

It serves as a foundation for understanding control structures and logic flow in embedded systems using C.

---

🧰 System Setup  
🖥️ Platform: PC (CLI)  
💬 Input: User types a float value  
📤 Output: Classification string describing system state

---

⚙️ Classification Logic

| Temperature Range | System Message                         |
|-------------------|----------------------------------------|
| < 0°C             | Freeze Warning: Enable heater          |
| 0°C – 19.9°C      | Heating ON — Cold Environment          |
| 20°C – 29.9°C     | Stable — No action needed              |
| == 30.0°C         | Threshold Alert                        |
| > 30°C            | Overheat! Cooling Fan ON               |

🧠 Built with a modular `char* classifyTemp(float)` logic function and full input validation.

---

💻 Code File  
`temp_classifier.c`

Key C concepts used:
- `scanf()` with validation
- `char*` return values
- `if-else` decision logic
- `float` variable handling
- Function abstraction

---

🧪 Sample Output
```bash
Enter temperature (°C): 32.5  
Temperature: 32.50 °C  
Overheat! Cooling Fan ON.
📎 Folder Structure
📂 Day13_C_Intro/
├── temp_classifier.c
├── temp_classifier.exe
└── README.md
```
## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University  

