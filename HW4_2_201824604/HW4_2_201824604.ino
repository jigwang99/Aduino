const int buttonPin = 14;
const int ledPins[] = {2, 3, 4, 5};
int currentLED = 0;
boolean forwardDirection = true;
boolean buttonState = LOW;
boolean lastButtonState = LOW;
unsigned long previousMillis = 0;
const long interval = 500; // 0.5 second interval

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      forwardDirection = !forwardDirection; // Toggle LED sequence direction
    }
    delay(50); // Debounce delay
  }
  lastButtonState = buttonState;
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (forwardDirection) {
      digitalWrite(ledPins[currentLED], LOW); // Turn off the current LED
      currentLED = (currentLED + 1) % 4; // Move to the next LED in forward direction
      digitalWrite(ledPins[currentLED], HIGH); // Turn on the next LED
    } else {
      digitalWrite(ledPins[currentLED], LOW); // Turn off the current LED
      currentLED = (currentLED - 1 + 4) % 4; // Move to the previous LED in backward direction
      digitalWrite(ledPins[currentLED], HIGH); // Turn on the previous LED
    }
  }
}
