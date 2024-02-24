int pin_button = 14; // Button pin
int pin_LED1 = 13, pin_LED2 = 2; // LED pins
unsigned long time_previous, time_current;
boolean LED_state1 = false; // LED1 state
boolean LED_state2 = false;
boolean buttonState = false; // Button state

void setup() {
  pinMode(pin_button, INPUT);
  pinMode(pin_LED1, OUTPUT);
  digitalWrite(pin_LED1, LED_state1);
  pinMode(pin_LED2, OUTPUT);
  digitalWrite(pin_LED2, LED_state2);
  time_previous = millis(); // Current time
}

void loop() {
  time_current = millis();
  if (time_current - time_previous >= 1000) {
    time_previous = time_current; // Update start time
    LED_state1 = !LED_state1; // LED1 status switching
    digitalWrite(pin_LED1, LED_state1);
  }

  // Check button state without delay
  boolean newButtonState = digitalRead(pin_button);
  if (newButtonState != buttonState) {
    buttonState = newButtonState; // Update the button state

    if (buttonState == HIGH) { // Button is pressed
      LED_state2 = !LED_state2; // LED2 status switching
      digitalWrite(pin_LED2, LED_state2);
    }
  }
}


