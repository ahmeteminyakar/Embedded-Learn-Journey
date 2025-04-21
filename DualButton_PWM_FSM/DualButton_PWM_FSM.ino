// === Pin Definitions ===
const int Led1Pin = 9;         // PWM pin for LED 1
const int Led2Pin = 10;        // PWM pin for LED 2

const int Button1Pin = 2;      // Button to increase brightness
const int Button2Pin = 3;      // Button to decrease brightness

// === FSM State Tracking ===
int lastButton1State = HIGH;
int lastButton2State = HIGH;
int state = 0;  // 0 = Very Low, 1 = Low, 2 = Medium, 3 = High

void setup() {
  pinMode(Led1Pin, OUTPUT);
  pinMode(Led2Pin, OUTPUT);
  pinMode(Button1Pin, INPUT_PULLUP);
  pinMode(Button2Pin, INPUT_PULLUP);
}

void loop() {
  int Button1State = digitalRead(Button1Pin);
  int Button2State = digitalRead(Button2Pin);

  // Increase brightness on Button1 press
  if (Button1State == LOW && lastButton1State == HIGH) {
    state = (state + 1) % 4;
    delay(200);  // debounce
  }

  // Decrease brightness on Button2 press
  if (Button2State == LOW && lastButton2State == HIGH) {
    state = (state + 3) % 4;  // equivalent to (state - 1 + 4) % 4
    delay(200);
  }

  // Set brightness according to current FSM state
  switch (state) {
    case 0:
      analogWrite(Led1Pin, 10);
      analogWrite(Led2Pin, 10);
      break;
    case 1:
      analogWrite(Led1Pin, 50);
      analogWrite(Led2Pin, 50);
      break;
    case 2:
      analogWrite(Led1Pin, 150);
      analogWrite(Led2Pin, 150);
      break;
    case 3:
      analogWrite(Led1Pin, 255);
      analogWrite(Led2Pin, 255);
      break;
  }

  // Update last button states
  lastButton1State = Button1State;
  lastButton2State = Button2State;
}
