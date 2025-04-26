# DHT11 Temperature & Humidity Monitor with 16x2 I2C LCD

## 📋 Project Overview
This Arduino project reads temperature and humidity data from a DHT11 sensor and displays the real-time values on a 16x2 I2C LCD display via I2C communication.  
Additionally, data is printed to the Serial Monitor for debugging and live monitoring.

---

## 🛠 Hardware Components
- Arduino UNO R3
- DHT11 Temperature and Humidity Sensor
- 16x2 LCD with I2C Interface (default I2C address: `0x27`)
- Breadboard (optional)
- Jumper Wires

---

## 🔌 Wiring Diagram

| Device         | Arduino Pin |
|:---------------|:------------|
| DHT11 VCC      | 5V          |
| DHT11 DATA     | D2          |
| DHT11 GND      | GND         |
| LCD VCC        | 5V          |
| LCD GND        | GND         |
| LCD SDA        | A4 (SDA)    |
| LCD SCL        | A5 (SCL)    |

---

## 🧩 Required Libraries
Install the following libraries via Arduino IDE Library Manager:
- `LiquidCrystal_I2C` by Frank de Brabander

---

## 🚀 How It Works
- Arduino sends a start signal to the DHT11 sensor.
- The DHT11 responds with humidity and temperature data.
- Arduino reads the data and displays it:
  - First row: Humidity (%)
  - Second row: Temperature (°C)
- Data updates automatically every 2 seconds.

---

## 🖥️ Example Serial Output

Humidity: 52% Temperature: 24°C


---

## 🔥 Future Development Ideas
- Add disconnection detection and error handling for DHT11.
- Log data onto an SD card module for long-term monitoring.
- Display maximum/minimum recorded humidity and temperature values.

---

## ❗ License
⚡ No formal license applied.  
This project is **open for educational and personal use**.  

---

## ✨ Author and Contact

- Developed by **Ahmet Emin Yakar**

### 🌐 Social Links
- [LinkedIn: Ahmet Emin Yakar](https://www.linkedin.com/in/ahmet-emin-yakar-bbb6732a6/) 
- [GitHub Profile](https://github.com/ahmeteminyakar)

---
