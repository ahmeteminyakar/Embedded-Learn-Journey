
const int Led1Pin = 9;
const int Led2Pin = 10;

const int Button1Pin = 2;
const int Button2Pin = 3;


int lastButton1State = HIGH;
int lastButton2State = HIGH;
int state = 0;


void setup() {
  pinMode(Led1Pin, OUTPUT);
  pinMode(Led2Pin, OUTPUT);
  pinMode(Button1Pin, INPUT_PULLUP);
  pinMode(Button2Pin, INPUT_PULLUP);
}

void loop() {

  int Button1State = digitalRead(Button1Pin);
  int Button2State = digitalRead(Button2Pin);

  if (Button1State == LOW && lastButton1State == HIGH) {

    state = (state + 1) % 4;
    delay(200);
  }

  if (Button2State == LOW && lastButton2State == HIGH) {

    state = (state + 3) % 4;
    delay(200);
  }


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

  lastButton1State = Button1State;
  lastButton2State = Button2State;
}
