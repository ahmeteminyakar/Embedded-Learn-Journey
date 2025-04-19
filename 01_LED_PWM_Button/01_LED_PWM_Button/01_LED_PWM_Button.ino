// === Pin Tanımları ===
const int ledPin = 9;           // PWM çıkışı olan pin
const int buttonPin = 2;        // Buton dijital girişi

int state = 0;                  // FSM durumu: 0 = Low, 1 = Med, 2 = High
int lastButtonState = HIGH;     // Önceki buton durumu (INPUT_PULLUP olduğundan varsayılan HIGH)

void setup() {
  pinMode(ledPin, OUTPUT);             // LED çıkış olarak tanımlanır
  pinMode(buttonPin, INPUT_PULLUP);    // Buton iç pull-up ile tanımlanır
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Mevcut buton durumu

  // Sadece yeni basış algılandığında state değiştir
  if (buttonState == LOW && lastButtonState == HIGH) {
    state = (state + 1) % 3;  // 3 durumluk FSM: 0→1→2→0
    delay(200);               // Debounce için kısa gecikme
  }

  // FSM’e göre PWM parlaklık seviyesini ayarla
  switch (state) {
    case 0:
      analogWrite(ledPin, 50);   // Düşük parlaklık
      break;
    case 1:
      analogWrite(ledPin, 150);  // Orta parlaklık
      break;
    case 2:
      analogWrite(ledPin, 255);  // Yüksek parlaklık
      break;
  }

  lastButtonState = buttonState; // Son durumu kaydet
}
