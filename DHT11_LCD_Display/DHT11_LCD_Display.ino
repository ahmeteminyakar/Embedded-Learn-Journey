#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 = Genellikle LCD modülün adresi

uint8_t humidity = 0;
uint8_t temperature = 0;

void setup() {
  Serial.begin(9600);
  lcd.init(); 
  lcd.backlight(); 
  delay(1000);
}

void loop() {
  DHT11_start();
  if (DHT11_check_response()) {
    humidity = DHT11_read();
    DHT11_read(); // Skip humidity decimal
    temperature = DHT11_read();
    DHT11_read(); // Skip temperature decimal
    DHT11_read(); // Skip checksum

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");
  } else {
    Serial.println("DHT11 did not respond!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT11 Error...");
  }
  delay(2000);
}

// DHT11 functions (same as before)

void DHT11_start() {
  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, LOW);
  delay(18);
  digitalWrite(DHTPIN, HIGH);
  delayMicroseconds(30);
  pinMode(DHTPIN, INPUT);
}

bool DHT11_check_response() {
  unsigned long start_time = micros();
  
  while (digitalRead(DHTPIN) == HIGH) {
    if (micros() - start_time > 100) return false;
  }
  
  start_time = micros();
  while (digitalRead(DHTPIN) == LOW) {
    if (micros() - start_time > 100) return false;
  }

  start_time = micros();
  while (digitalRead(DHTPIN) == HIGH) {
    if (micros() - start_time > 100) return false;
  }
  
  return true;
}

uint8_t DHT11_read() {
  uint8_t result = 0;
  for (int i = 0; i < 8; i++) {
    while (digitalRead(DHTPIN) == LOW);
    delayMicroseconds(30);
    if (digitalRead(DHTPIN) == HIGH)
      result |= (1 << (7 - i));
    while (digitalRead(DHTPIN) == HIGH);
  }
  return result;
}
