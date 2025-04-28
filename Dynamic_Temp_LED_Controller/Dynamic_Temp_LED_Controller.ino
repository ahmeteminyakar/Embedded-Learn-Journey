#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define Ledpin 5

DHT dht(DHTPIN, DHTTYPE);

int delay_time;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(Ledpin, OUTPUT);
}

void handleTemperature(float temp) {
    if (temp > 30) {
      analogWrite(Ledpin, 255);
      delay_time = 1000;
      Serial.println("🔥 WARNING: HIGH TEMP!");
    }
    else if (temp >= 25 && temp < 30) {
      analogWrite(Ledpin, 155);
      delay_time = 2000;
    }
    else if (temp >= 0 && temp < 25) {
      analogWrite(Ledpin, 50);
      delay_time = 3000;
    }
    else {
      Serial.println("❌ ERROR: Invalid Temperature!");
      analogWrite(Ledpin, 0); // Turn off LED
      delay_time = 3000;
    }
}

void loop() {
  float temp = 0.0;

  if (Serial.available() > 0) {
    temp = Serial.parseFloat();

    if (isnan(temp)) {
      Serial.println("Invalid Input!");
      return;
    }

    Serial.print("Received Temperature: ");
    Serial.println(temp);

    handleTemperature(temp);

    Serial.print("Waiting for ");
    Serial.print(delay_time / 1000);
    Serial.println(" seconds...");

    delay(delay_time);
  }
}
