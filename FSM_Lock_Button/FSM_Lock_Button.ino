// === Pin Definitions ===
const int ledpin = 9;             // LED output pin
const int button1pin = 2;         // First button (step 1)
const int button2pin = 3;         // Second button (step 2)

// === FSM and State Tracking ===
int state = 0;                    // Current FSM state
int lb1st = HIGH;                 // Last state of button 1
int lb2st = HIGH;                 // Last state of button 2

void setup() {
  pinMode(ledpin, OUTPUT);        // Set LED pin as output
  pinMode(button1pin, INPUT_PULLUP); // Enable pull-up for button 1
  pinMode(button2pin, INPUT_PULLUP); // Enable pull-up for button 2
}

void loop() {
  int bt1state = digitalRead(button1pin);  // Read current state of button 1
  int bt2state = digitalRead(button2pin);  // Read current state of button 2

  switch (state) {
    case 0:
      // Step 1: Press Button 1 to proceed
      if (bt1state == LOW && lb1st == HIGH) {
        state = 1;
        delay(200); // Debounce
      }
      break;

    case 1:
      // Step 2: Press Button 2 to proceed
      if (bt2state == LOW && lb2st == HIGH) {
        state = 2;
        delay(200); // Debounce
      }
      break;

    case 2:
      // Step 3: Press Button 1 again to activate lock
      if (bt1state == LOW && lb1st == HIGH) {
        state = 3; // System enters locked mode
        delay(200); // Debounce
      }
      break;

    case 3:
      // LOCKED STATE: LED stays ON and loop halts
      digitalWrite(ledpin, HIGH); // Turn LED ON
      while (true) {
        // System is locked – no further actions
      }
      break;
  }

  // Update last button states for edge detection
  lb1st = bt1state;
  lb2st = bt2state;
}