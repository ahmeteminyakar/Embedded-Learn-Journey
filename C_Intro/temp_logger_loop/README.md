# 🌡️ Temperature Logger with Loop and Array – C

This C program collects 5 temperature readings from the user, stores them in an array, prints the values in **reverse order**, calculates the **average**, and issues alerts if any value exceeds a safe threshold.

It's built to practice and demonstrate core concepts in **looping**, **array indexing**, **input validation**, and **system monitoring logic** — all essential skills for embedded systems development.

---

## ✅ Features

- Uses a `for` loop to collect and process input
- Stores all temperatures in a `float` array
- Reverses output order (latest reading shown first)
- Calculates average of all inputs
- Issues an alert if any value exceeds `35.0°C`

---

## 🧠 Key Concepts Practiced

| Concept           | Description                                      |
|------------------|--------------------------------------------------|
| `for` loop        | Controlled iteration over sensor inputs         |
| `float temps[5]`  | Array used for batch reading storage            |
| Input validation | Rejects non-numeric input using `scanf()` guard |
| Reverse loop     | Demonstrates countdown loop logic (`i--`)       |
| Alert system     | Threshold-based decision during iteration       |

---

## 💻 Sample Output

```bash
Enter temperature 1: 23.5  
Enter temperature 2: 25.0  
Enter temperature 3: 42.3  
Enter temperature 4: 30.0  
Enter temperature 5: 20.0

--- Logged Temperatures ---
Temp 5: 20.00 °C  
Temp 4: 30.00 °C  
Temp 3: 42.30 °C  
⚠️  ALERT: Temp 3 is above safe threshold!
Temp 2: 25.00 °C  
Temp 1: 23.50 °C

Average Temperature: 28.56 °C
```

## 🔗 Connect
📌 [LinkedIn – Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6)  
🎓 Electrical & Electronics Engineering Student – Gazi University 