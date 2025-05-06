#include <EEPROM.h>

const int MAX_LOGS = 10;
unsigned long lastLogTime = 0;
uint8_t writeIndex = 0;  // 0 to 9

struct LogEntry {
  uint32_t timestamp;
  float temperature;
};

void setup() {
  Serial.begin(9600);

  // Load last index from EEPROM[0]
  writeIndex = EEPROM.read(0);

  Serial.println("EEPROM Logger Ready");
}



void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastLogTime >= 10000) {  // Every 10s
    lastLogTime = currentTime;

    // Simulate a temperature value
    float temperature = 24.0 + (writeIndex * 0.5);  // Fake data

    LogEntry log;
    log.timestamp = currentTime;
    log.temperature = temperature;

    // Calculate EEPROM address to write to
    int address = 1 + (writeIndex * sizeof(LogEntry));
    EEPROM.put(address, log);

    // Update and store write index
    writeIndex = (writeIndex + 1) % MAX_LOGS;
    EEPROM.write(0, writeIndex);

    Serial.print("Logged to slot ");
    Serial.println(writeIndex);
  }
}



