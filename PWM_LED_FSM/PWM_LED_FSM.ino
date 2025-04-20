// === Pin definitions ===
const int ledPin = 9;           // PWM output pin for the LED
const int buttonPin = 2;        // Digital input pin for the button

// === FSM and button state tracking ===
int state = 0;                  // FSM state: 0 = Low, 1 = Medium, 2 = High
int lastButtonState = HIGH;     // Stores the previous button state

void setup() {
  pinMode(ledPin, OUTPUT);             // Set LED pin as output
  pinMode(buttonPin, INPUT_PULLUP);    // Enable internal pull-up for the button
}

void loop() {
  int buttonState = digitalRead(buttonPin);  // Read current button state

  // Detect new button press (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    state = (state + 1) % 3;  // Cy cle through 3 states: 0 → 1 → 2 → 0
    delay(200);               // Simple debounce delay
  }

  // Adjust LED brightness based on FSM state
  switch (state) {
    case 0:
      analogWrite(ledPin, 50);   // Low brightness
      break;
    case 1:
      analogWrite(ledPin, 150);  // Medium brightness
      break;
    case 2:
      analogWrite(ledPin, 255);  // High brightness
      break;
    

  }
  
  lastButtonState = buttonState;  // Update button state for next loop
  
}
