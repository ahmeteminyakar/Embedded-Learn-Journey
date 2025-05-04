void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = 25.4;
  float hum = 63.2;

  String data = "TEMP:" + String(temp, 2) + ";HUM:" + String(hum, 2);

  // ✅ Calculate checksum = sum of chars % 256
  byte checksum = 0;
  for (int i = 0; i < data.length(); i++) {
    checksum += data[i];
  }

  // ✅ Send: data*checksum
  Serial.print(data);
  Serial.print("*");
  Serial.println(checksum);

  delay(2000);
}
