const int ledpin = 9;
const int button1pin = 2;
const int button2pin = 3;

int state = 0;

int lb1st = HIGH;
int lb2st = HIGH;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
}

void loop() {
  int bt1state = digitalRead(button1pin);
  int bt2state = digitalRead(button2pin);

  switch (state) {
    case 0:
      if (bt1state == LOW && lb1st == HIGH) {
        state = 1;
        delay(200);
      }
      break;

    case 1:
      if (bt2state == LOW && lb2st == HIGH) {
        state = 2;
        delay(200);
      }
      break;

    case 2:
      if (bt1state == LOW && lb1st == HIGH) {
        state = 3;  // Kilitli
        delay(200);
      }
      break;

    case 3:
      digitalWrite(ledpin, HIGH); // kilitli mod
      while (true) {
        // Sistem kilitli
      }
      break;
  }

  lb1st = bt1state;
  lb2st = bt2state;
}
