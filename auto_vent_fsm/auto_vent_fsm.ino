#include <DHT.h>

// === CONFIGURATION ===
#define DHTPIN 2
#define DHTTYPE DHT11
#define LEDPIN 9

DHT dht(DHTPIN, DHTTYPE);

// === FSM STATES ===
enum State { IDLE,
             VENT_WAIT,
             VENT_ACTIVE };
State currentState = IDLE;

// === TIMERS ===
unsigned long previousMillis = 0;
const long interval = 2000;

unsigned long stateEntryTime = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  float temp, humidity;

  // Sensor read every 2 seconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    temp = dht.readTemperature();
    humidity = dht.readHumidity();

    if (isnan(temp) || isnan(humidity)) {
      Serial.println("❌ Sensor read failed.");
      return;
    }

    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // === FSM TRANSITIONS ===
    switch (currentState) {
      case IDLE:
        if (temp >= 28.0) {
          currentState = VENT_WAIT;
          stateEntryTime = millis();  // Start 10s timer
          Serial.println(" Transition: IDLE → VENT_WAIT");
        }
        break;

      case VENT_WAIT:
        if (temp < 26.0) {
          currentState = IDLE;
          Serial.println(" Transition: VENT_WAIT → IDLE");
        } else if (millis() - stateEntryTime >= 10000) {
          currentState = VENT_ACTIVE;
          Serial.println(" Transition: VENT_WAIT → VENT_ACTIVE");
        }
        break;

      case VENT_ACTIVE:
        if (temp < 26.0) {
          currentState = IDLE;
          Serial.println(" Transition: VENT_ACTIVE → IDLE");
        }
        break;
    }
  }

  // === OUTPUT ACTIONS ===
  switch (currentState) {
    case IDLE:
      digitalWrite(LEDPIN, LOW);
      break;

    case VENT_WAIT:
      blinkLED();
      break;

    case VENT_ACTIVE:
      digitalWrite(LEDPIN, HIGH);
      break;
  }
}

void blinkLED() {
  digitalWrite(LEDPIN, HIGH);
  delay(400);
  digitalWrite(LEDPIN, LOW);
  delay(400);
}
